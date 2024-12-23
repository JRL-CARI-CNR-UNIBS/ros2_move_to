#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/string.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "ik_solver_msgs/srv/get_ik.hpp"
#include "ik_solver_msgs/msg/ik_solution.hpp"
#include "ik_solver_msgs/msg/configuration.hpp"
#include "ik_solver_msgs/srv/get_bound.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include "cnr_param/cnr_param.h"
#include "trajectory_loader/action/move_to_action.hpp"

#include <moveit/move_group_interface/move_group_interface.h>
#include "moveit/trajectory_processing/iterative_spline_parameterization.h"
#include "moveit/trajectory_processing/time_optimal_trajectory_generation.h"

#include "control_msgs/control_msgs/action/follow_joint_trajectory.hpp"

using namespace std::chrono_literals;

class MoveToServer : public rclcpp::Node
{
public:
    explicit MoveToServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
        : Node("move_to_server", node_options)
    {
        // Subscribe to the available /get_ik services
        std::vector<std::string> ik_services, bound_services;
        rclcpp::Rate rate(100);

        while(ik_services.empty() || (ik_services.size() != bound_services.size()))
        {
            RCLCPP_DEBUG_THROTTLE(this->get_logger(),*this->get_clock(),1000,"Waiting for /get_ik services");

            this->getAvailableIkAndBoundService(ik_services, bound_services);
            rate.sleep();
        }

        RCLCPP_WARN_STREAM(this->get_logger(),"Available /get_ik services:");
        std::pair<std::string,rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedPtr> p_ik;
        for(const std::string& service: ik_services)
        {
            p_ik.first = service;
            p_ik.second = this->create_client<ik_solver_msgs::srv::GetIk>(p_ik.first);

            this->ik_client_map_.insert(p_ik);

            RCLCPP_WARN_STREAM(this->get_logger(),"  -"<<service<<"\n");
        }

        RCLCPP_WARN_STREAM(this->get_logger(),"Available /get_bound services:");
        std::pair<std::string,rclcpp::Client<ik_solver_msgs::srv::GetBound>::SharedPtr> p_bound;
        for(const std::string& service: bound_services)
        {
            p_bound.first = service;
            p_bound.second = this->create_client<ik_solver_msgs::srv::GetBound>(p_bound.first);

            this->bound_client_map_.insert(p_bound);

            RCLCPP_WARN_STREAM(this->get_logger(),"  -"<<service<<"\n");
        }

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

        this->action_server_ = rclcpp_action::create_server<trajectory_loader::action::MoveToAction>(
                    this,"move_to",
                    std::bind(&MoveToServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
                    std::bind(&MoveToServer::handle_cancel, this, std::placeholders::_1),
                    std::bind(&MoveToServer::handle_accepted, this, std::placeholders::_1));
    }
private:
    bool fjt_error_;
    bool fjt_finished_;
    bool ik_response_received_;
    bool bound_response_received_;
    ik_solver_msgs::srv::GetIk::Response::SharedPtr ik_response_;
    ik_solver_msgs::srv::GetBound::Response::SharedPtr bound_response_;
    rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr scaling_pub_;
    rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
    rclcpp_action::Server<trajectory_loader::action::MoveToAction>::SharedPtr action_server_;
    std::map<std::string,rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedPtr> ik_client_map_;
    std::map<std::string,rclcpp::Client<ik_solver_msgs::srv::GetBound>::SharedPtr> bound_client_map_;
    rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client_;
    std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::MoveToAction>> goal_handle_;

    struct Ik{
        std::vector<std::string> joint_names;
        std::vector<ik_solver_msgs::msg::Configuration> configurations;
    };

    void ik_response_callback(rclcpp::Client<ik_solver_msgs::srv::GetIk>::SharedFuture future)
    {
        this->ik_response_received_ = true;
        this->ik_response_ = future.get();
    }

    void bound_response_callback(rclcpp::Client<ik_solver_msgs::srv::GetBound>::SharedFuture future)
    {
        this->bound_response_received_ = true;
        this->bound_response_ = future.get();
    }

    void getAvailableIkAndBoundService(std::vector<std::string>& ik_service, std::vector<std::string>& bound_service)
    {
        std::string ik_target_type = "ik_solver_msgs/srv/GetIk";
        std::string bound_target_type = "ik_solver_msgs/srv/GetBound";

        ik_service.clear();
        bound_service.clear();
        for(const std::pair<std::string, std::vector<std::string>> service: this->get_service_names_and_types())
        {
            for(const std::string& type: service.second)
            {
                if(type == ik_target_type)
                    ik_service.push_back(service.first);
                else if (type == bound_target_type)
                    bound_service.push_back(service.first);
            }
        }
    }

    bool getJointsNames(const std::string& bound_service, std::vector<std::string>& joint_names)
    {
        auto req = std::make_shared<ik_solver_msgs::srv::GetBound::Request>();
        auto result = this->bound_client_map_.at(bound_service)->async_send_request(req, std::bind(&MoveToServer::bound_response_callback,
                                                                                             this, std::placeholders::_1));
        rclcpp::Rate rate(100);
        while(not this->bound_response_received_)
        {
            RCLCPP_DEBUG_THROTTLE(this->get_logger(),*this->get_clock(),1000,"Waiting for /get_bound server response");
            rate.sleep();
        }

        if(this->bound_response_ != nullptr)
        {
            joint_names.clear();
            for(const auto& b:this->bound_response_.get()->boundaries)
            {
                joint_names.push_back(b.joint_name);
                RCLCPP_INFO_STREAM(this->get_logger(),"\n - joint: "<<b.joint_name<<" min: "<<b.lower_bound<<" max: "<<b.upper_bound);
            }
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Bound service failed");
            return false;
        }
        return true;
    }

    bool getIk(const std::string& ik_service, const geometry_msgs::msg::PoseStamped& pose, const std::vector<double>& current_configuration, Ik& ik)
    {
        auto req = std::make_shared<ik_solver_msgs::srv::GetIk::Request>();
        ik_solver_msgs::msg::IkTarget target;
        ik_solver_msgs::msg::Configuration seed;
        seed.configuration = current_configuration;

        target.pose = pose;
        target.seeds.push_back(seed);
        req->target = target;

        this->ik_response_ = nullptr;
        this->ik_response_received_ = false;
        auto result = this->ik_client_map_.at(ik_service)->async_send_request(req, std::bind(&MoveToServer::ik_response_callback,
                                                                                             this, std::placeholders::_1));
        rclcpp::Rate rate(100);
        while(not this->ik_response_received_)
        {
            RCLCPP_DEBUG_THROTTLE(this->get_logger(),*this->get_clock(),1000,"Waiting for /get_ik server response");
            rate.sleep();
        }

        if(this->ik_response_ != nullptr)
        {
            ik.joint_names = this->ik_response_.get()->joint_names;
            ik.configurations = this->ik_response_.get()->solution.configurations;
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Ik service failed");
            return false;
        }
        return true;
    }

    bool chooseIk(const Ik& ik, const std::vector<double>& current_configuration, const std::vector<double>& joints_weights, std::vector<double>& best_ik)
    {
        Eigen::VectorXd best_conf;
        Eigen::VectorXd current_conf = Eigen::VectorXd::Map(
                    current_configuration.data(), static_cast<Eigen::Index>(current_configuration.size()));

        Eigen::VectorXd weights;

        if (joints_weights.size() == current_conf.size())
        {
            weights = Eigen::VectorXd::Map(joints_weights.data(), joints_weights.size());
        }
        else if (joints_weights.size() > current_conf.size())
        {
            weights = Eigen::VectorXd::Map(joints_weights.data(), current_conf.size());
        }
        else
        {
            weights = Eigen::VectorXd::Map(joints_weights.data(), joints_weights.size());
            weights.conservativeResize(current_conf.size());
            weights.tail(current_conf.size() - joints_weights.size()).setOnes();
        }

        if (joints_weights.size() != current_conf.size())
        {
            RCLCPP_WARN_STREAM(this->get_logger(),
                               "Warning: The size of the joints_weights vector (" << joints_weights.size() << ") "
                               << "is different from the size of the current_configuration vector (DOF: "
                               << current_conf.size() << "). "
                               << "If joints_weights' size is less than DOF, missing weights are set to 1.0. If it is greater, only the first "
                               <<current_conf.size()<<" weights will be used. "<< "Weights after adjustment: " << weights.transpose());
        }

        double distance;
        double min_distance = std::numeric_limits<double>::infinity();

        for(size_t i=0;i<ik.configurations.size();i++)
        {
            Eigen::VectorXd conf = Eigen::VectorXd::Map(
                        ik.configurations[i].configuration.data(),
                        static_cast<Eigen::Index>(ik.configurations[i].configuration.size()));

            distance = ((conf-current_conf).cwiseProduct(weights)).norm();
            if(distance<min_distance)
            {
                best_conf = conf;
                min_distance = distance;
            }
        }

        best_ik.resize(best_conf.size());
        Eigen::Map<Eigen::VectorXd>(best_ik.data(), best_ik.size()) = best_conf;
        RCLCPP_INFO_STREAM(get_logger(), "Selected ik has distance = " << min_distance);

        return true;
    }

    void move_to()
    {
        auto result = std::make_shared<trajectory_loader::action::MoveToAction::Result>();
        auto feedback = std::make_shared<trajectory_loader::action::MoveToAction::Feedback>();

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
                std::bind(&MoveToServer::result_callback, this, std::placeholders::_1);

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
        summary = summary+" - ik_service_name: "+goal->ik_service_name+"\n";
        summary = summary+" - speed_scaling_topic: "+goal->speed_scaling_topic+"\n";
        summary = summary+" - scaling: "+std::to_string(goal->scaling)+"\n";
        summary = summary+" - simulation: "+(goal->simulation? "true": "false")+"\n";
        summary = summary+" - pipeline_id: "+std::to_string(goal->pipeline_id)+"\n";
        summary = summary+" - planner_id: "+std::to_string(goal->planner_id)+"\n";
        summary = summary+" - acceleration_scaling_factor: "+std::to_string(goal->acceleration_scaling_factor)+"\n";
        summary = summary+" - velocity_scaling_factor: "+std::to_string(goal->velocity_scaling_factor)+"\n";
        summary = summary+" - joints weights: [ "; for(const auto &s:goal->joints_weights) summary = summary+std::to_string(s)+" "; summary = summary+"]\n";
        summary = summary+" - pose:\n"+geometry_msgs::msg::to_yaml(goal->pose);

        RCLCPP_WARN_STREAM(this->get_logger(),summary);

        this->scaling_pub_->publish(scaling);

        if (this->ik_client_map_.find(goal->ik_service_name) == this->ik_client_map_.end())
        {
            RCLCPP_ERROR(this->get_logger(),"Required ik service not available");

            std::vector<std::string> s;
            for(const auto& p:this->ik_client_map_)
                s.push_back(" - "+p.first+"\n");

            RCLCPP_ERROR_STREAM(this->get_logger(),"List of /get_ik services detected:\n");

            result->error = "Required ik service not available";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }

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

        std::string bound_service = goal->ik_service_name;
        size_t pos = bound_service.find("get_ik");

        if (pos != std::string::npos)
            bound_service.replace(pos, 7, "get_bounds");

        std::vector<std::string> joint_names;
        if(not this->getJointsNames(bound_service,joint_names))
        {
            RCLCPP_ERROR(this->get_logger(),"unable to get joint names");
            result->error ="unable to get joint names";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }

        RCLCPP_INFO(this->get_logger(),"Waiting for robot current state");
        moveit::core::RobotStatePtr robot_current_state = move_group.getCurrentState();
        std::vector<double> current_configuration;
        for(const std::string& j:joint_names)
        {
            double d = *robot_current_state->getJointPositions(j);
            current_configuration.push_back(d);
        }

        std::string txt_current_state = "Current configuration read:";
        std::vector<std::string> all_joints = move_group.getActiveJoints();
        for(auto j: all_joints)
            txt_current_state = txt_current_state+"\n\t- Joint: "+std::to_string(j)+" -> "+std::to_string(*robot_current_state->getJointPositions(j));

        RCLCPP_INFO_STREAM(this->get_logger(),txt_current_state);

        Ik ik;
        if(not this->getIk(goal->ik_service_name,goal->pose,current_configuration,ik))
        {
            RCLCPP_ERROR(this->get_logger(),"Ik not available");
            result->error = "Ik not available";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }

        if(ik.configurations.size()!=0)
            RCLCPP_INFO_STREAM(this->get_logger(),ik.configurations.size()<<" ik available");
        else
        {
            RCLCPP_ERROR(this->get_logger(),"No ik available");
            result->error = "No ik available";
            this->goal_handle_->abort(result);
            this->clear();
            return;
        }

        std::vector<double> best_ik;
        this->chooseIk(ik,current_configuration,goal->joints_weights,best_ik);

        std::string best_ik_str = "";
        for(const double& d : best_ik)
            best_ik_str = best_ik_str + std::to_string(d)+" ";

        RCLCPP_INFO_STREAM(this->get_logger(),"Choosen ik: "<<best_ik_str);


        Eigen::VectorXd current_conf = Eigen::VectorXd::Map(
                    current_configuration.data(), static_cast<Eigen::Index>(current_configuration.size()));
        Eigen::VectorXd tmp_ik = Eigen::VectorXd::Map(
                    best_ik.data(), static_cast<Eigen::Index>(best_ik.size()));
        Eigen::VectorXd tmp_w = Eigen::VectorXd::Map(
                    goal->joints_weights.data(), static_cast<Eigen::Index>(goal->joints_weights.size()));

        RCLCPP_INFO_STREAM(this->get_logger(),"current conf "<<current_conf.transpose());

        RCLCPP_WARN_STREAM(this->get_logger(),"diff conf "<<(tmp_ik-current_conf).transpose());
        RCLCPP_WARN_STREAM(this->get_logger(),"weighted "<<((tmp_ik-current_conf).cwiseProduct(tmp_w)).transpose());
        RCLCPP_WARN_STREAM(this->get_logger(),"norm "<<((tmp_ik-current_conf).cwiseProduct(tmp_w)).norm());

        std::map<std::string, double> goal_map;
        for(size_t j=0;j<all_joints.size();j++)
        {
            std::pair<std::string, double> p;
            p.first = all_joints[j];

            auto it = std::find(ik.joint_names.begin(),ik.joint_names.end(),all_joints[j]);
            if(it != ik.joint_names.end())
                p.second = best_ik[std::distance(ik.joint_names.begin(),it)];
            else
                p.second = *robot_current_state.get()->getJointPositions(p.first); //if the joint is not considered by the ik solver, keep it at its current position

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

            //      moveit::core::MoveItErrorCode moveit_error_code = move_group.execute(trj);
            //      if(moveit_error_code != moveit::core::MoveItErrorCode::SUCCESS)
            //      {
            //        RCLCPP_ERROR_STREAM(this->get_logger(), "Move group move failed with error code "
            //                            <<moveit::core::error_code_to_string(moveit_error_code));
            //        result->error = "Move group move failed with error code "+moveit::core::error_code_to_string(moveit_error_code);
            //        goal_handle_->abort(result);
            //        return;
            //      }

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
            std::shared_ptr<const trajectory_loader::action::MoveToAction::Goal> goal)
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
            <trajectory_loader::action::MoveToAction>> goal_handle)
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
                         <trajectory_loader::action::MoveToAction>> goal_handle)
    {
        this->goal_handle_ = goal_handle;
        //    goal_handle_->execute();
        std::thread(std::bind(&MoveToServer::move_to, this)).detach();
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
    auto node = std::make_shared<MoveToServer>(node_options);

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
