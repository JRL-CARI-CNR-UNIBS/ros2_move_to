// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__TRAITS_HPP_
#define TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "trajectory_loader/action/detail/trajectory_loader_action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: group_name
  {
    out << "group_name: ";
    rosidl_generator_traits::value_to_yaml(msg.group_name, out);
    out << ", ";
  }

  // member: trj_names
  {
    if (msg.trj_names.size() == 0) {
      out << "trj_names: []";
    } else {
      out << "trj_names: [";
      size_t pending_items = msg.trj_names.size();
      for (auto item : msg.trj_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: repetitions
  {
    out << "repetitions: ";
    rosidl_generator_traits::value_to_yaml(msg.repetitions, out);
    out << ", ";
  }

  // member: rescale
  {
    out << "rescale: ";
    rosidl_generator_traits::value_to_yaml(msg.rescale, out);
    out << ", ";
  }

  // member: simulation
  {
    out << "simulation: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: group_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "group_name: ";
    rosidl_generator_traits::value_to_yaml(msg.group_name, out);
    out << "\n";
  }

  // member: trj_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.trj_names.size() == 0) {
      out << "trj_names: []\n";
    } else {
      out << "trj_names:\n";
      for (auto item : msg.trj_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: repetitions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "repetitions: ";
    rosidl_generator_traits::value_to_yaml(msg.repetitions, out);
    out << "\n";
  }

  // member: rescale
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rescale: ";
    rosidl_generator_traits::value_to_yaml(msg.rescale, out);
    out << "\n";
  }

  // member: simulation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "simulation: ";
    rosidl_generator_traits::value_to_yaml(msg.simulation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_Goal & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_Goal>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_Goal";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_Goal>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_Goal";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: ok
  {
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ok: ";
    rosidl_generator_traits::value_to_yaml(msg.ok, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_Result & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_Result>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_Result";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_Result>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_Result";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: trj_in_execution
  {
    out << "trj_in_execution: ";
    rosidl_generator_traits::value_to_yaml(msg.trj_in_execution, out);
    out << ", ";
  }

  // member: current_repetition
  {
    out << "current_repetition: ";
    rosidl_generator_traits::value_to_yaml(msg.current_repetition, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trj_in_execution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trj_in_execution: ";
    rosidl_generator_traits::value_to_yaml(msg.trj_in_execution, out);
    out << "\n";
  }

  // member: current_repetition
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_repetition: ";
    rosidl_generator_traits::value_to_yaml(msg.current_repetition, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_Feedback & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_Feedback>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_Feedback";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_Feedback>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_Feedback";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "trajectory_loader/action/detail/trajectory_loader_action__traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_SendGoal_Request";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_SendGoal_Response";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_SendGoal>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_SendGoal";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_SendGoal>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_SendGoal";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>::value &&
    has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>::value &&
    has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<trajectory_loader::action::TrajectoryLoaderAction_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_GetResult_Request";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_GetResult_Response";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Result>::value> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Result>::value> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_GetResult>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_GetResult";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_GetResult>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_GetResult";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>::value &&
    has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>::value &&
    has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>::value
  >
{
};

template<>
struct is_service<trajectory_loader::action::TrajectoryLoaderAction_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__traits.hpp"

namespace trajectory_loader
{

namespace action
{

inline void to_flow_style_yaml(
  const TrajectoryLoaderAction_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryLoaderAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryLoaderAction_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace trajectory_loader

namespace rosidl_generator_traits
{

[[deprecated("use trajectory_loader::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  trajectory_loader::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use trajectory_loader::action::to_yaml() instead")]]
inline std::string to_yaml(const trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage & msg)
{
  return trajectory_loader::action::to_yaml(msg);
}

template<>
inline const char * data_type<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>()
{
  return "trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage";
}

template<>
inline const char * name<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>()
{
  return "trajectory_loader/action/TrajectoryLoaderAction_FeedbackMessage";
}

template<>
struct has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<trajectory_loader::action::TrajectoryLoaderAction_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<trajectory_loader::action::TrajectoryLoaderAction_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<trajectory_loader::action::TrajectoryLoaderAction>
  : std::true_type
{
};

template<>
struct is_action_goal<trajectory_loader::action::TrajectoryLoaderAction_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<trajectory_loader::action::TrajectoryLoaderAction_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<trajectory_loader::action::TrajectoryLoaderAction_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__TRAITS_HPP_
