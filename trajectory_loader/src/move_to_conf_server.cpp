#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/string.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"

#include "cnr_param/cnr_param.h"
#include "trajectory_loader/action/move_to_conf_action.hpp"

#include <moveit/move_group_interface/move_group_interface.h>
#include "moveit/trajectory_processing/iterative_spline_parameterization.h"
#include "moveit/trajectory_processing/time_optimal_trajectory_generation.h"

#include "control_msgs/control_msgs/action/follow_joint_trajectory.hpp"

using namespace std::chrono_literals;

class MoveToConfServer : public rclcpp::Node
{
public:
    explicit MoveToConfServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
        : Node("move_to_conf_server", node_options)
    {
        this->display_trj_pub_ = this->create_publisher<moveit_msgs::msg::DisplayTrajectory>("/simulated_trajectory",1);

        // Get robot_description
        rclcpp::SyncParametersClient::SharedPtr parameters_client = std::make_shared<rclcpp::SyncParametersClient>(this, std::string("/move_group"));
        while (!parameters_client->wait_for_service(1s))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                rclcpp::shutdown();
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }
        if(not parameters_client->has_parameter("robot_description"))
            RCLCPP_ERROR(this->get_logger(), "Cannot find robot_description parameter");
        if(not parameters_client->has_parameter("robot_description_semantic"))
            RCLCPP_ERROR(this->get_logger(), "Cannot find robot_description_semantic parameter");

        std::string param_name = "robot_description";
        std::string robot_description = parameters_client->get_parameter<std::string>(param_name);

        rclcpp::Parameter robot_description_param(param_name,robot_description);
        this->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
        this->set_parameter(robot_description_param);

        if(not this->has_parameter(param_name))
            throw std::runtime_error("no robot description");
        else
            RCLCPP_WARN(this->get_logger(),"robot description loaded");

        param_name = "robot_description_semantic";
        std::string robot_description_semantic = parameters_client->get_parameter<std::string>(param_name);

        rclcpp::Parameter robot_description_semantic_param(param_name,robot_description_semantic);
        this->declare_parameter(param_name, rclcpp::PARAMETER_STRING);
        this->set_parameter(robot_description_semantic_param);

        if(not this->has_parameter(param_name))
            throw std::runtime_error("no robot description semantic");
        else
            RCLCPP_WARN(this->get_logger(),"robot description semantic loaded");

        this->action_server_ = rclcpp_action::create_server<trajectory_loader::action::MoveToConfAction>(
                    this,"move_to_conf",
                    std::bind(&MoveToConfServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
                    std::bind(&MoveToConfServer::handle_cancel, this, std::placeholders::_1),
                    std::bind(&MoveToConfServer::handle_accepted, this, std::placeholders::_1));
    }
private:
    bool fjt_error_;
    bool fjt_finished_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr scaling_pub_;
    rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
    rclcpp_action::Server<trajectory_loader::action::MoveToConfAction>::SharedPtr action_server_;
    rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client_;
    std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::MoveToConfAction>> goal_handle_;

    void move_to_conf()
    {
        auto result = std::make_shared<trajectory_loader::action::MoveToConfAction::Result>();
        auto feedback = std::make_shared<trajectory_loader::action::MoveToConfAction::Feedback>();

        result->ok = false;
        const auto goal = this->goal_handle_->get_goal();

        this->action_client_ = rclcpp_action::create_client<control_msgs::action::FollowJointTrajectory>(this,goal->fjt_action_name);
        this->scaling_pub_ = this->create_publisher<std_msgs::msg::Int16>(goal->speed_scaling_topic,1);

        if(!this->action_client_->wait_for_action_server())
        {
            RCLCPP_ERROR(this->get_logger(), "Action server %s not available after waiting", goal->fjt_action_name.c_str());
            result->error = "Fjt Action server not available after waiting";
            this->goal_handle_->abort(result);
            this->clear();

            return;
        }

        auto send_goal_options = rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SendGoalOptions();
        send_goal_options.result_callback =
                std::bind(&MoveToConfServer::result_callback, this, std::placeholders::_1);

        std_msgs::msg::Int16 scaling;
        if(goal->scaling<0)
        {
            RCLCPP_WARN_STREAM(this->get_logger(), "Scaling cannot be negative, set to 0");
            scaling.data = 0;
        }
        else if(goal->scaling>100)
        {
            RCLCPP_WARN_STREAM(this->get_logger(), "Scaling cannot be greater than 100, set to 100");
            scaling.data = 100;
        }
        else
        {
            scaling.data = goal->scaling;
        }

        std::string summary = "Request:\n";
        summary = summary+" - group_name: "+goal->group_name+"\n";
        summary = summary+" - fjt_action_name: "+goal->fjt_action_name+"\n";
        summary = summary+" - speed_scaling_topic: "+goal->speed_scaling_topic+"\n";
        summary = summary+" - scaling: "+std::to_string(goal->scaling)+"\n";
        summary = summary+" - simulation: "+(goal->simulation? "true": "false")+"\n";
        summary = summary+" - pipeline_id: "+std::to_string(goal->pipeline_id)+"\n";
        summary = summary+" - planner_id: "+std::to_string(goal->planner_id)+"\n";
        summary = summary+" - acceleration_scaling_factor: "+std::to_string(goal->acceleration_scaling_factor)+"\n";
        summary = summary+" - velocity_scaling_factor: "+std::to_string(goal->velocity_scaling_factor)+"\n";
        summary = summary+" - target_joints_configurations: [ "; for(const auto &s:goal->target_joints_configurations) summary = summary+std::to_string(s)+" "; summary = summary+"]\n";
        summary = summary+" - joints_names: [ "; for(const auto &s:goal->joints_names) summary = summary+std::to_string(s)+" "; summary = summary+"]\n";

        RCLCPP_WARN_STREAM(this->get_logger(),summary);

        this->scaling_pub_->publish(scaling);

        bool success;
        moveit::planning_interface::MoveGroupInterface::Plan plan;
        moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),goal->group_name);

        if(this->goal_handle_->is_canceling())
        {
            RCLCPP_INFO(this->get_logger(),"Goal canceled");
            result->error="canceled";
            this->goal_handle_->canceled(result);
            this->clear();
            return;
        }

        RCLCPP_INFO(this->get_logger(),"Starting state monitor");
        if (!move_group.startStateMonitor())
        {
            RCLCPP_ERROR(this->get_logger(),"unable to read current state");
            result->error ="unable to read current state";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }

        RCLCPP_INFO(this->get_logger(),"Waiting for robot current state");
        moveit::core::RobotStatePtr robot_current_state = move_group.getCurrentState();
        std::vector<double> current_configuration;
        for(const std::string& j:goal->joints_names)
        {
            double d = *robot_current_state->getJointPositions(j);
            current_configuration.push_back(d);
        }

        std::string txt_current_state = "Current configuration read:";
        std::vector<std::string> all_joints = move_group.getActiveJoints();
        for(auto j: all_joints)
            txt_current_state = txt_current_state+"\n\t- Joint: "+std::to_string(j)+" -> "+std::to_string(*robot_current_state->getJointPositions(j));

        RCLCPP_INFO_STREAM(this->get_logger(),txt_current_state);

        std::map<std::string, double> goal_map;
        for(size_t j=0;j<all_joints.size();j++)
        {
            std::pair<std::string, double> p;
            p.first = all_joints[j];

            auto it = std::find(goal->joints_names.begin(),goal->joints_names.end(),all_joints[j]);
            if(it != goal->joints_names.end())
                p.second = goal->target_joints_configurations[std::distance(goal->joints_names.begin(),it)];
            else
                p.second = *robot_current_state.get()->getJointPositions(p.first); //if the joint is not considered, keep it at its current position

            goal_map.insert(p);
        }

        if(this->goal_handle_->is_canceling())
        {
            RCLCPP_INFO(this->get_logger(),"Goal canceled");
            result->error="canceled";
            this->goal_handle_->canceled(result);
            this->clear();
            return;
        }

        move_group.setJointValueTarget(goal_map);

        // set pipeline and planner
        move_group.setPlanningPipelineId(goal->pipeline_id);
        move_group.setPlannerId(goal->planner_id);
        move_group.setMaxAccelerationScalingFactor(goal->acceleration_scaling_factor);
        move_group.setMaxVelocityScalingFactor(goal->velocity_scaling_factor);

        robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), goal->group_name);
        success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
        if(not success)
        {
            RCLCPP_ERROR(this->get_logger(),"Planning to location failed!");
            result->error = "planning failed!";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }
        // plan.trajectory_.joint_trajectory (path without motion law)

        moveit_msgs::msg::RobotTrajectory trj;
        trajectory.setRobotTrajectoryMsg(*robot_current_state, plan.trajectory_.joint_trajectory);

        // TIME PARAMETRIZATION
        trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
        trj_processing.computeTimeStamps(trajectory);
        trajectory.getRobotTrajectoryMsg(trj);

        RCLCPP_DEBUG_STREAM(this->get_logger(),trajectory);

        if(this->goal_handle_->is_canceling())
        {
            RCLCPP_INFO(this->get_logger(),"Goal canceled");
            result->error="canceled";
            this->goal_handle_->canceled(result);
            this->clear();
            return;
        }

        if(not goal->simulation)
        {
            this->fjt_error_ = false;
            this->fjt_finished_ = false;
            auto goal_msg = control_msgs::action::FollowJointTrajectory::Goal();
            goal_msg.trajectory = trj.joint_trajectory;
            this->action_client_->async_send_goal(goal_msg, send_goal_options);

            rclcpp::Rate rate(100);
            while(not this->fjt_finished_)
            {
                RCLCPP_INFO_THROTTLE(this->get_logger(),*this->get_clock(),1000,"Approach: Waiting end of fjt action");
                rate.sleep();
            }

            if(this->fjt_error_)
            {
                RCLCPP_INFO(this->get_logger(),"Fjt action had an error, aborted or canceled");
                result->error="fjt error, aborted or canceled";
                this->goal_handle_->abort(result);
                this->clear();
                return;
            }

            if(this->goal_handle_->is_canceling())
            {
                RCLCPP_INFO(this->get_logger(),"Goal canceled");
                result->error="canceled";
                this->goal_handle_->canceled(result);
                this->clear();
                return;
            }
        }
        else
        {
            moveit_msgs::msg::DisplayTrajectory display_trj_msg;
            display_trj_msg.trajectory.push_back(trj);
            this->display_trj_pub_->publish(display_trj_msg);

            rclcpp::sleep_for(std::chrono::nanoseconds(
                                  rclcpp::Duration(trj.joint_trajectory.points.back().time_from_start).nanoseconds()));
        }

        result->ok=true;
        this->goal_handle_->succeed(result);

        this->clear();

        return;
    }

    rclcpp_action::GoalResponse handle_goal(
            const rclcpp_action::GoalUUID & uuid,
            std::shared_ptr<const trajectory_loader::action::MoveToConfAction::Goal> goal)
    {
        RCLCPP_INFO_STREAM(this->get_logger(), "Received goal request for group "<< goal->group_name);

        if(this->goal_handle_ != nullptr)
        {
            if(this->goal_handle_->is_active()    ||
                    this->goal_handle_->is_canceling() ||
                    this->goal_handle_->is_executing())
            {
                RCLCPP_INFO_STREAM(this->get_logger(), "Goal rejected! Current goal not in a terminal state");
                return rclcpp_action::GoalResponse::REJECT;
            }
        }

        (void)uuid;

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
            const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <trajectory_loader::action::MoveToConfAction>> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

        if(this->action_client_ != nullptr)
        {
            RCLCPP_INFO(this->get_logger(), "Asking to fjt to cancel all goals");
            this->action_client_->async_cancel_all_goals();
        }

        (void)goal_handle;
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
                         <trajectory_loader::action::MoveToConfAction>> goal_handle)
    {
        this->goal_handle_ = goal_handle;
        //    goal_handle_->execute();
        std::thread(std::bind(&MoveToConfServer::move_to_conf, this)).detach();
    }

    void result_callback(const rclcpp_action::ClientGoalHandle<control_msgs::action::FollowJointTrajectory>::WrappedResult & result)
    {
        switch (result.code) {
        case rclcpp_action::ResultCode::SUCCEEDED:
            break;
        case rclcpp_action::ResultCode::ABORTED:
            this->fjt_error_ = true;
            RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
            break;
        case rclcpp_action::ResultCode::CANCELED:
            this->fjt_error_ = true;
            RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
            break;
        default:
            RCLCPP_ERROR(this->get_logger(), "Unknown result code");
            this->fjt_error_ = true;
            break;
        }
        this->fjt_finished_ = true;
        return;
    }

    void clear()
    {
        this->scaling_pub_ = nullptr;
        this->action_client_ = nullptr;
        this->fjt_error_ = false;
        this->fjt_finished_ = false;
    }
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    auto node = std::make_shared<MoveToConfServer>(node_options);

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
