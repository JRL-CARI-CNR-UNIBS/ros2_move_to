// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__BUILDER_HPP_
#define TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "trajectory_loader/action/detail/trajectory_loader_action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_Goal_simulation
{
public:
  explicit Init_TrajectoryLoaderAction_Goal_simulation(::trajectory_loader::action::TrajectoryLoaderAction_Goal & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal simulation(::trajectory_loader::action::TrajectoryLoaderAction_Goal::_simulation_type arg)
  {
    msg_.simulation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal msg_;
};

class Init_TrajectoryLoaderAction_Goal_rescale
{
public:
  explicit Init_TrajectoryLoaderAction_Goal_rescale(::trajectory_loader::action::TrajectoryLoaderAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TrajectoryLoaderAction_Goal_simulation rescale(::trajectory_loader::action::TrajectoryLoaderAction_Goal::_rescale_type arg)
  {
    msg_.rescale = std::move(arg);
    return Init_TrajectoryLoaderAction_Goal_simulation(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal msg_;
};

class Init_TrajectoryLoaderAction_Goal_repetitions
{
public:
  explicit Init_TrajectoryLoaderAction_Goal_repetitions(::trajectory_loader::action::TrajectoryLoaderAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TrajectoryLoaderAction_Goal_rescale repetitions(::trajectory_loader::action::TrajectoryLoaderAction_Goal::_repetitions_type arg)
  {
    msg_.repetitions = std::move(arg);
    return Init_TrajectoryLoaderAction_Goal_rescale(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal msg_;
};

class Init_TrajectoryLoaderAction_Goal_trj_names
{
public:
  explicit Init_TrajectoryLoaderAction_Goal_trj_names(::trajectory_loader::action::TrajectoryLoaderAction_Goal & msg)
  : msg_(msg)
  {}
  Init_TrajectoryLoaderAction_Goal_repetitions trj_names(::trajectory_loader::action::TrajectoryLoaderAction_Goal::_trj_names_type arg)
  {
    msg_.trj_names = std::move(arg);
    return Init_TrajectoryLoaderAction_Goal_repetitions(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal msg_;
};

class Init_TrajectoryLoaderAction_Goal_group_name
{
public:
  Init_TrajectoryLoaderAction_Goal_group_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_Goal_trj_names group_name(::trajectory_loader::action::TrajectoryLoaderAction_Goal::_group_name_type arg)
  {
    msg_.group_name = std::move(arg);
    return Init_TrajectoryLoaderAction_Goal_trj_names(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_Goal>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_Goal_group_name();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_Result_error
{
public:
  explicit Init_TrajectoryLoaderAction_Result_error(::trajectory_loader::action::TrajectoryLoaderAction_Result & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_Result error(::trajectory_loader::action::TrajectoryLoaderAction_Result::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Result msg_;
};

class Init_TrajectoryLoaderAction_Result_ok
{
public:
  Init_TrajectoryLoaderAction_Result_ok()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_Result_error ok(::trajectory_loader::action::TrajectoryLoaderAction_Result::_ok_type arg)
  {
    msg_.ok = std::move(arg);
    return Init_TrajectoryLoaderAction_Result_error(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_Result>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_Result_ok();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_Feedback_current_repetition
{
public:
  explicit Init_TrajectoryLoaderAction_Feedback_current_repetition(::trajectory_loader::action::TrajectoryLoaderAction_Feedback & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_Feedback current_repetition(::trajectory_loader::action::TrajectoryLoaderAction_Feedback::_current_repetition_type arg)
  {
    msg_.current_repetition = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Feedback msg_;
};

class Init_TrajectoryLoaderAction_Feedback_trj_in_execution
{
public:
  Init_TrajectoryLoaderAction_Feedback_trj_in_execution()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_Feedback_current_repetition trj_in_execution(::trajectory_loader::action::TrajectoryLoaderAction_Feedback::_trj_in_execution_type arg)
  {
    msg_.trj_in_execution = std::move(arg);
    return Init_TrajectoryLoaderAction_Feedback_current_repetition(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_Feedback>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_Feedback_trj_in_execution();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_SendGoal_Request_goal
{
public:
  explicit Init_TrajectoryLoaderAction_SendGoal_Request_goal(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request goal(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request msg_;
};

class Init_TrajectoryLoaderAction_SendGoal_Request_goal_id
{
public:
  Init_TrajectoryLoaderAction_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_SendGoal_Request_goal goal_id(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TrajectoryLoaderAction_SendGoal_Request_goal(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_SendGoal_Request_goal_id();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_SendGoal_Response_stamp
{
public:
  explicit Init_TrajectoryLoaderAction_SendGoal_Response_stamp(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response stamp(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response msg_;
};

class Init_TrajectoryLoaderAction_SendGoal_Response_accepted
{
public:
  Init_TrajectoryLoaderAction_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_SendGoal_Response_stamp accepted(::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_TrajectoryLoaderAction_SendGoal_Response_stamp(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_SendGoal_Response_accepted();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_GetResult_Request_goal_id
{
public:
  Init_TrajectoryLoaderAction_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request goal_id(::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_GetResult_Request_goal_id();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_GetResult_Response_result
{
public:
  explicit Init_TrajectoryLoaderAction_GetResult_Response_result(::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response result(::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response msg_;
};

class Init_TrajectoryLoaderAction_GetResult_Response_status
{
public:
  Init_TrajectoryLoaderAction_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_GetResult_Response_result status(::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_TrajectoryLoaderAction_GetResult_Response_result(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_GetResult_Response_status();
}

}  // namespace trajectory_loader


namespace trajectory_loader
{

namespace action
{

namespace builder
{

class Init_TrajectoryLoaderAction_FeedbackMessage_feedback
{
public:
  explicit Init_TrajectoryLoaderAction_FeedbackMessage_feedback(::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage feedback(::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage msg_;
};

class Init_TrajectoryLoaderAction_FeedbackMessage_goal_id
{
public:
  Init_TrajectoryLoaderAction_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryLoaderAction_FeedbackMessage_feedback goal_id(::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_TrajectoryLoaderAction_FeedbackMessage_feedback(msg_);
  }

private:
  ::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>()
{
  return trajectory_loader::action::builder::Init_TrajectoryLoaderAction_FeedbackMessage_goal_id();
}

}  // namespace trajectory_loader

#endif  // TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__BUILDER_HPP_
