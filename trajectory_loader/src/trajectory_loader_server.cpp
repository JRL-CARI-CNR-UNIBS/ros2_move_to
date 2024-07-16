#include "rclcpp/rclcpp.hpp"
#include <rclcpp/parameter_client.hpp>
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "std_msgs/msg/int16.hpp"
#include "std_msgs/msg/string.hpp"
#include "builtin_interfaces/msg/duration.hpp"
#include "moveit_msgs/msg/display_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"

#include "cnr_param/cnr_param.h"
#include "trajectory_loader/action/trajectory_loader_action.hpp"

#include "moveit/move_group_interface/move_group_interface.h"
#include "moveit/trajectory_processing/iterative_spline_parameterization.h"
#include "moveit/trajectory_processing/time_optimal_trajectory_generation.h"

#include "control_msgs/control_msgs/action/follow_joint_trajectory.hpp"

using namespace std::chrono_literals;

class TrajectoryLoaderServer : public rclcpp::Node
{
public:
  explicit TrajectoryLoaderServer(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
    : Node("trajectory_loader_server", node_options)
  {
    this->action_server_ = rclcpp_action::create_server<trajectory_loader::action::TrajectoryLoaderAction>(
          this,"trajectory_loader",
          std::bind(&TrajectoryLoaderServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&TrajectoryLoaderServer::handle_cancel, this, std::placeholders::_1),
          std::bind(&TrajectoryLoaderServer::handle_accepted, this, std::placeholders::_1));

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
  }

private:
  bool fjt_error_;
  bool fjt_finished_;
  rclcpp::Publisher<std_msgs::msg::Int16>::SharedPtr scaling_pub_;
  rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_trj_pub_;
  rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>::SharedPtr action_client_;
  rclcpp_action::Server<trajectory_loader::action::TrajectoryLoaderAction>::SharedPtr action_server_;
  std::shared_ptr<rclcpp_action::ServerGoalHandle<trajectory_loader::action::TrajectoryLoaderAction>> goal_handle_;

  void load_trajectory()
  {
    auto result = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Result>();
    auto feedback = std::make_shared<trajectory_loader::action::TrajectoryLoaderAction::Feedback>();

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
        std::bind(&TrajectoryLoaderServer::result_callback, this, std::placeholders::_1);

    std::string summary = "Request:\n";
    summary = summary+" - trj: [";
    for(size_t i=0;i<goal->trj_names.size();i++)
    {
      if(i == goal->trj_names.size()-1)
        summary = summary+goal->trj_names[i]+"]\n";
      else
        summary = summary+goal->trj_names[i]+", ";
    }

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

    summary = summary+" - group_name: "+goal->group_name+"\n";
    summary = summary+" - fjt_action_name: "+goal->fjt_action_name+"\n";
    summary = summary+" - speed_scaling_topic: "+goal->speed_scaling_topic+"\n";
    summary = summary+" - scaling: "+std::to_string(goal->scaling)+"\n";
    summary = summary+" - repetitions: "+std::to_string(goal->repetitions)+"\n";
    summary = summary+" - recompute_time_law: "+(goal->recompute_time_law? "true": "false")+"\n";
    summary = summary+" - simulation: "+(goal->simulation? "true": "false")+"\n";

    RCLCPP_WARN_STREAM(this->get_logger(),summary);

    bool success;
    bool recompute_time_law;
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    moveit::planning_interface::MoveGroupInterface move_group(this->shared_from_this(),goal->group_name);

    if (!move_group.startStateMonitor())
    {
      RCLCPP_ERROR(this->get_logger(),"unable to read current state");
      result->error ="unable to read current state";
      this->goal_handle_->abort(result);
      this->clear();
      return;
    }

    moveit::core::RobotState robot_current_state = *move_group.getCurrentState(10);

    for(int irep = 0; irep<goal->repetitions; irep++)
    {
      for(const std::string& trj_name : goal->trj_names)
      {
        this->scaling_pub_->publish(scaling);

        if(goal_handle_->is_canceling())
        {
          RCLCPP_INFO(this->get_logger(),"Goal canceled");
          result->error="canceled";
          this->goal_handle_->canceled(result);
          this->clear();

          return;
        }
        recompute_time_law = goal->recompute_time_law;
        robot_current_state = *move_group.getCurrentState(10);

        feedback->current_repetition = irep;
        feedback->trj_in_execution = trj_name;

        this->goal_handle_->publish_feedback(feedback);

        moveit_msgs::msg::RobotTrajectory trj;
        moveit_msgs::msg::RobotTrajectory approach_trj;
        trajectory_msgs::msg::JointTrajectory trj_from_param;

        std::string what;
        if(not getTrajectoryFromParam(trj_name, trj_from_param, what))
        {
          RCLCPP_ERROR(this->get_logger(),"%s not found", trj_name.c_str());
          RCLCPP_ERROR_STREAM(this->get_logger(), what);

          result->error = trj_name+" not found";
          this->goal_handle_->abort(result);
          this->clear();

          return;
        }
        else
        {
          if(rclcpp::Duration(trj_from_param.points.back().time_from_start) == rclcpp::Duration::from_seconds(0.0))
            recompute_time_law = true;
        }

        if(goal_handle_->is_canceling())
        {
          RCLCPP_INFO(this->get_logger(),"Goal canceled");
          result->error="canceled";
          this->goal_handle_->canceled(result);
          this->clear();

          return;
        }

        std::vector<double> initial_trj_position = trj_from_param.points.begin()->positions;

        bool is_single_point = false;
        if(trj_from_param.points.size() < 2)
        {
          is_single_point = true;
          trj.joint_trajectory = trj_from_param;
          RCLCPP_WARN_STREAM(this->get_logger(),"Single point trajectory!");
        }
        else
        {
          if(recompute_time_law)
          {
            robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), goal->group_name);
            trajectory.setRobotTrajectoryMsg(robot_current_state, trj_from_param);

            trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
            trj_processing.computeTimeStamps(trajectory);
            trajectory.getRobotTrajectoryMsg(trj);

            RCLCPP_WARN(this->get_logger(),"Trajectory is scaled");
          }
          else
            trj.joint_trajectory=trj_from_param;
        }

        if(this->goal_handle_->is_canceling())
        {
          RCLCPP_INFO(this->get_logger(),"Goal canceled");
          result->error="canceled";
          this->goal_handle_->canceled(result);
          this->clear();

          return;
        }

        //Go to the first configuration of the trajectory
        std::map<std::string, double> target_configuration;
        for(size_t j=0;j<trj_from_param.joint_names.size();j++)
        {
          std::pair<std::string, double> p;
          p.first = trj_from_param.joint_names[j];
          p.second = initial_trj_position[j];
          target_configuration.insert(p);
          RCLCPP_ERROR_STREAM(this->get_logger(),"target_configuration = " <<  p.first << ": " << p.second);
        }

        if (!move_group.startStateMonitor())
        {
          RCLCPP_ERROR(this->get_logger(),"unable to read current state");
          result->error ="unable to read current state";
          this->goal_handle_->abort(result);
          this->clear();
          return;
        }
        move_group.setStartStateToCurrentState();
        moveit::core::RobotStatePtr start_state = move_group.getCurrentState();
        robot_current_state.printStateInfo();

        move_group.setJointValueTarget(target_configuration);

        robot_trajectory::RobotTrajectory trajectory(move_group.getRobotModel(), goal->group_name);
        success = (move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS);
        if(not success)
        {
          RCLCPP_ERROR(this->get_logger(),"Planning to initial trj position failed!");
          result->error = "planning failed!";
          this->goal_handle_->abort(result);
          this->clear();

          return;
        }

        trajectory.setRobotTrajectoryMsg(robot_current_state, plan.trajectory_.joint_trajectory);
        trajectory_processing::TimeOptimalTrajectoryGeneration trj_processing;
        trj_processing.computeTimeStamps(trajectory);
        trajectory.getRobotTrajectoryMsg(approach_trj);

        RCLCPP_INFO_STREAM(this->get_logger(),"Approach trj\n"<<trajectory);

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
          // Execute approach trajectory
          RCLCPP_INFO(this->get_logger(),"Move %s to initial position", goal->group_name.c_str());

          this->fjt_error_ = false;
          this->fjt_finished_ = false;
          auto goal_msg = control_msgs::action::FollowJointTrajectory::Goal();
          goal_msg.trajectory = approach_trj.joint_trajectory;


          for (const trajectory_msgs::msg::JointTrajectoryPoint& p: goal_msg.trajectory.points)
          {
            std::cout << "approach point = ";
            for (const double& j: p.positions)
            {
              std::cout << j << ", ";
            }
            std::cout << "approach velocities = ";
            for (const double& j: p.velocities)
            {
              std::cout << j << ", ";
            }
            std::cout << std::endl;
          }

          this->action_client_->async_send_goal(goal_msg, send_goal_options);

          rclcpp::Rate rate(100);
          while(not this->fjt_finished_)
          {
            RCLCPP_INFO(this->get_logger(),"Approach: Waiting end of fjt action");
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

          //          moveit::core::MoveItErrorCode moveit_error_code = move_group.execute(approach_trj);
          //          if(moveit_error_code != moveit::core::MoveItErrorCode::SUCCESS)
          //          {
          //            RCLCPP_ERROR_STREAM(this->get_logger(), "Move group move failed with error code "
          //                                <<moveit::core::error_code_to_string(moveit_error_code));
          //            result->error = "Move group move failed with error code "+moveit::core::error_code_to_string(moveit_error_code);
          //            goal_handle_->abort(result);
          //            return;
          //          }

          if(this->goal_handle_->is_canceling())
          {
            RCLCPP_INFO(this->get_logger(),"Goal canceled");
            result->error="canceled";
            this->goal_handle_->canceled(result);
            this->clear();

            return;
          }

          rclcpp::sleep_for(std::chrono::milliseconds(50));

          if(not is_single_point)
          {
            // Execute the trajectory
            RCLCPP_INFO(this->get_logger(), "Execute trajectory %s", trj_name.c_str());

            this->fjt_error_ = false;
            this->fjt_finished_ = false;
            auto goal_msg = control_msgs::action::FollowJointTrajectory::Goal();
            goal_msg.trajectory = trj.joint_trajectory;


            for (const trajectory_msgs::msg::JointTrajectoryPoint& p: goal_msg.trajectory.points)
            {
              std::cout << "parameters point = ";
              for (const double& j: p.positions)
              {
                std::cout << j << ", ";
              }
              std::cout << "parameters velocities = ";
              for (const double& j: p.velocities)
              {
                std::cout << j << ", ";
              }
              std::cout << std::endl;
            }


            this->action_client_->async_send_goal(goal_msg, send_goal_options);

            rclcpp::Rate rate(100);
            while(not this->fjt_finished_)
            {
              RCLCPP_INFO(this->get_logger(),"Execute: Waiting end of fjt action");
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

            rclcpp::sleep_for(std::chrono::milliseconds(50));
          }
        }
        else
        {
          moveit_msgs::msg::DisplayTrajectory display_trj_msg;
          display_trj_msg.trajectory.push_back(approach_trj);
          this->display_trj_pub_->publish(display_trj_msg);

          rclcpp::sleep_for(std::chrono::nanoseconds(
                              rclcpp::Duration(approach_trj.joint_trajectory.points.back().time_from_start).nanoseconds()));

          if(this->goal_handle_->is_canceling())
          {
            RCLCPP_INFO(this->get_logger(),"Goal canceled");
            result->error="canceled";
            this->goal_handle_->canceled(result);
            this->clear();

            return;
          }
          display_trj_msg.trajectory.at(0)=trj;
          this->display_trj_pub_->publish(display_trj_msg);
          rclcpp::sleep_for(std::chrono::nanoseconds(
                              rclcpp::Duration(trj.joint_trajectory.points.back().time_from_start).nanoseconds()));
        }
      }
    }

    result->ok=true;
    this->goal_handle_->succeed(result);
    this->clear();

    return;
  }

  template<typename T>
  bool checkd(const std::vector<T>& in, const size_t& dim, const std::string& id, std::string& what)
  {
    bool ret = in.size() == dim;
    if(!ret)
    {
      what += std::string(what.length()>0 ? "\n" : "") +
          "The vector '" + id + "' dimension is '"+ std::to_string(in.size()) + "' but '"+std::to_string(dim)+"' is expected";
    }
    return ret;
  }

  bool getTrajectoryFromParam(const std::string& trj_name, trajectory_msgs::msg::JointTrajectory& trj, std::string& what)
  {
    RCLCPP_INFO(this->get_logger(),"Reading trajectory %s from param ",trj_name.c_str());

    std::vector<std::string>          n;
    std::vector<double>               t;
    std::vector<std::vector<double>>  q, qd, qdd, eff;

    std::vector<std::string> params =
    {"joint_names", "time_from_start", "positions", "velocities", "accelerations", "effort" };

    for(size_t i=0; i<params.size(); i++)
    {
      std::string w;
      bool ok = true;
      std::string ns = "/"+trj_name+"/"+params.at(i);
      switch(i)
      {
      case 0:
        //joint names is mandatory
        ok = cnr::param::get(ns,n,w);
        break;
      case 1:
        //time is not mandatory
        cnr::param::get(ns,t,w);
        break;
      case 2:
        //q is mandatory
        ok = cnr::param::get(ns,q,w);
        break;
      case 3:
        //qd is not mandatory
        cnr::param::get(ns,qd,w);
        break;
      case 4:
        //qdd is not mandatory
        cnr::param::get(ns,qdd,w);
        break;
      case 5:
        //effort is not mandatory
        cnr::param::get(ns,eff,w);
        break;
      }
      what += (what.length()>0 && w.length()>0 ? "\n" : "") + w;
      if(not ok)
        return false;
    }

    if((q.size() == 0) || (q.at(0).size() == 0))
    {
      what += trj_name + "/positions is broken";
      return false;
    }

    size_t np = q.size();
    size_t dof = q.at(0).size();

    if((n.size()==0 || !checkd(n, dof, "joint_names", what))
       || (t.size()!=0 && !checkd(t, np , "time_from_start", what))
       || (qd.size()!=0 && !checkd(qd, np , "velocities", what))
       || (qdd.size()!=0 && !checkd(qdd, np , "accelerations", what))
       || (eff.size()!=0 && !checkd(eff, np , "effort", what) ))
    {
      return false;
    }

    std::map< std::string, std::vector<std::vector<double>>& > checks =
    {{"position", q}, {"velocity", qd}, {"acceleration", qdd}, {"effort", eff}};

    for(const auto & cc : checks )
    {
      if(cc.second.size()!=0)
      {
        for(size_t i=0;i<np;i++)
        {
          if( !checkd( cc.second.at(i) , dof, cc.first +"#" + std::to_string(i), what))
            return false;
        }
      }
    }

    // TRJ MODIFICATION == == == == == == == == == == == == == ==
    trj.joint_names = n;
    trj.points.clear();
    trj.points.resize(np);

    for (size_t i=0;i<np;i++)
    {
      trj.points.at(i).positions = q.at(i);
      if (qd.size()>0)
      {
        trj.points.at(i).velocities = qd.at(i);
      }
      if (qdd.size()>0)
      {
        trj.points.at(i).accelerations = qdd.at(i);
      }
      if (eff.size()>0)
      {
        trj.points.at(i).effort = eff.at(i);
      }

      builtin_interfaces::msg::Duration duration;
      if(t.size()>0)
        duration = rclcpp::Duration::from_seconds(t.at(i));
      else
        duration = rclcpp::Duration::from_seconds(0.0);

      trj.points.at(i).time_from_start = duration;
    }

    RCLCPP_INFO_STREAM(this->get_logger(),"Trajectory read from param positions:");
    for(size_t i=0;i<np;i++)
    {
      std::string pos = "";
      unsigned int n=0;
      for(const auto& d:trj.points.at(i).positions)
      {
        pos = pos+std::to_string(d)+ " ";
      }
      RCLCPP_INFO_STREAM(this->get_logger(),"point "<<n<<": ["<<pos<<"]");
    }

    return true;
  }

  rclcpp_action::GoalResponse handle_goal(
      const rclcpp_action::GoalUUID & uuid,
      std::shared_ptr<const trajectory_loader::action::TrajectoryLoaderAction::Goal> goal)
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

    if(goal->repetitions < 1)
    {
      RCLCPP_ERROR_STREAM(this->get_logger(),"repetitions cannot be less than 1, current value "<<goal->repetitions);
      return rclcpp_action::GoalResponse::REJECT;
    }

    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
      const std::shared_ptr<rclcpp_action::ServerGoalHandle
      <trajectory_loader::action::TrajectoryLoaderAction>> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");

    if(this->action_client_ != nullptr)
    {
      RCLCPP_INFO(this->get_logger(), "Asking to fjt to cancel all goals");
      action_client_->async_cancel_all_goals();
    }

    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
                       <trajectory_loader::action::TrajectoryLoaderAction>> goal_handle)
  {
    this->goal_handle_ = goal_handle;
    //    goal_handle_->execute();
    std::thread(std::bind(&TrajectoryLoaderServer::load_trajectory, this)).detach();
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
  auto node = std::make_shared<TrajectoryLoaderServer>(node_options);

  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();

  rclcpp::shutdown();

  return 0;
}
