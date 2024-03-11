// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_H_
#define TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'group_name'
// Member 'trj_names'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Goal
{
  rosidl_runtime_c__String group_name;
  rosidl_runtime_c__String__Sequence trj_names;
  int32_t repetitions;
  bool rescale;
  bool simulation;
} trajectory_loader__action__TrajectoryLoaderAction_Goal;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_Goal.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Result
{
  bool ok;
  rosidl_runtime_c__String error;
} trajectory_loader__action__TrajectoryLoaderAction_Result;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_Result.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'trj_in_execution'
// Member 'current_repetition'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Feedback
{
  rosidl_runtime_c__String trj_in_execution;
  rosidl_runtime_c__String current_repetition;
} trajectory_loader__action__TrajectoryLoaderAction_Feedback;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_Feedback.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  trajectory_loader__action__TrajectoryLoaderAction_Goal goal;
} trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response
{
  int8_t status;
  trajectory_loader__action__TrajectoryLoaderAction_Result result;
} trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.h"

/// Struct defined in action/TrajectoryLoaderAction in the package trajectory_loader.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  trajectory_loader__action__TrajectoryLoaderAction_Feedback feedback;
} trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage;

// Struct for a sequence of trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage.
typedef struct trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence
{
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_H_
