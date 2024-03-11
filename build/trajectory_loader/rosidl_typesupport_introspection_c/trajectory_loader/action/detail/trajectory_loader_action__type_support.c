// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
#include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
#include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `group_name`
// Member `trj_names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_Goal__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(message_memory);
}

size_t trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__size_function__TrajectoryLoaderAction_Goal__trj_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_const_function__TrajectoryLoaderAction_Goal__trj_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_function__TrajectoryLoaderAction_Goal__trj_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__fetch_function__TrajectoryLoaderAction_Goal__trj_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_const_function__TrajectoryLoaderAction_Goal__trj_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__assign_function__TrajectoryLoaderAction_Goal__trj_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_function__TrajectoryLoaderAction_Goal__trj_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__resize_function__TrajectoryLoaderAction_Goal__trj_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_member_array[5] = {
  {
    "group_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Goal, group_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trj_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Goal, trj_names),  // bytes offset in struct
    NULL,  // default value
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__size_function__TrajectoryLoaderAction_Goal__trj_names,  // size() function pointer
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_const_function__TrajectoryLoaderAction_Goal__trj_names,  // get_const(index) function pointer
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__get_function__TrajectoryLoaderAction_Goal__trj_names,  // get(index) function pointer
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__fetch_function__TrajectoryLoaderAction_Goal__trj_names,  // fetch(index, &value) function pointer
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__assign_function__TrajectoryLoaderAction_Goal__trj_names,  // assign(index, value) function pointer
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__resize_function__TrajectoryLoaderAction_Goal__trj_names  // resize(index) function pointer
  },
  {
    "repetitions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Goal, repetitions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rescale",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Goal, rescale),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "simulation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Goal, simulation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_Goal",  // message name
  5,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal),
  trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Goal)() {
  if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_Goal__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_Result__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_member_array[2] = {
  {
    "ok",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Result, ok),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Result, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_Result",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result),
  trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Result)() {
  if (!trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_Result__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `trj_in_execution`
// Member `current_repetition`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_member_array[2] = {
  {
    "trj_in_execution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Feedback, trj_in_execution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_repetition",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_Feedback, current_repetition),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_Feedback",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback),
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Feedback)() {
  if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_Feedback__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trajectory_loader/action/trajectory_loader_action.h"
// Member `goal`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request),
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Request)() {
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Goal)();
  if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response),
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Response)() {
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_members = {
  "trajectory_loader__action",  // service namespace
  "TrajectoryLoaderAction_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_type_support_handle = {
  0,
  &trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal)() {
  if (!trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_SendGoal_Response)()->data;
  }

  return &trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request),
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Request)() {
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trajectory_loader/action/trajectory_loader_action.h"
// Member `result`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response),
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Response)() {
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Result)();
  if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_members = {
  "trajectory_loader__action",  // service namespace
  "TrajectoryLoaderAction_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_type_support_handle = {
  0,
  &trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult)() {
  if (!trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_GetResult_Response)()->data;
  }

  return &trajectory_loader__action__detail__trajectory_loader_action__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trajectory_loader/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trajectory_loader/action/trajectory_loader_action.h"
// Member `feedback`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__init(message_memory);
}

void trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_fini_function(void * message_memory)
{
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_members = {
  "trajectory_loader__action",  // message namespace
  "TrajectoryLoaderAction_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage),
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_member_array,  // message members
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_type_support_handle = {
  0,
  &trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trajectory_loader
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_FeedbackMessage)() {
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_loader, action, TrajectoryLoaderAction_Feedback)();
  if (!trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__rosidl_typesupport_introspection_c__TrajectoryLoaderAction_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
