// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice
#include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `group_name`
// Member `trj_names`
#include "rosidl_runtime_c/string_functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__init(trajectory_loader__action__TrajectoryLoaderAction_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__init(&msg->group_name)) {
    trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(msg);
    return false;
  }
  // trj_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->trj_names, 0)) {
    trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(msg);
    return false;
  }
  // repetitions
  // rescale
  // simulation
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(trajectory_loader__action__TrajectoryLoaderAction_Goal * msg)
{
  if (!msg) {
    return;
  }
  // group_name
  rosidl_runtime_c__String__fini(&msg->group_name);
  // trj_names
  rosidl_runtime_c__String__Sequence__fini(&msg->trj_names);
  // repetitions
  // rescale
  // simulation
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Goal * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->group_name), &(rhs->group_name)))
  {
    return false;
  }
  // trj_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->trj_names), &(rhs->trj_names)))
  {
    return false;
  }
  // repetitions
  if (lhs->repetitions != rhs->repetitions) {
    return false;
  }
  // rescale
  if (lhs->rescale != rhs->rescale) {
    return false;
  }
  // simulation
  if (lhs->simulation != rhs->simulation) {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Goal * input,
  trajectory_loader__action__TrajectoryLoaderAction_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__copy(
      &(input->group_name), &(output->group_name)))
  {
    return false;
  }
  // trj_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->trj_names), &(output->trj_names)))
  {
    return false;
  }
  // repetitions
  output->repetitions = input->repetitions;
  // rescale
  output->rescale = input->rescale;
  // simulation
  output->simulation = input->simulation;
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_Goal *
trajectory_loader__action__TrajectoryLoaderAction_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Goal * msg = (trajectory_loader__action__TrajectoryLoaderAction_Goal *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Goal__destroy(trajectory_loader__action__TrajectoryLoaderAction_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Goal * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_Goal *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_Goal * data =
      (trajectory_loader__action__TrajectoryLoaderAction_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_Result__init(trajectory_loader__action__TrajectoryLoaderAction_Result * msg)
{
  if (!msg) {
    return false;
  }
  // ok
  // error
  if (!rosidl_runtime_c__String__init(&msg->error)) {
    trajectory_loader__action__TrajectoryLoaderAction_Result__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Result__fini(trajectory_loader__action__TrajectoryLoaderAction_Result * msg)
{
  if (!msg) {
    return;
  }
  // ok
  // error
  rosidl_runtime_c__String__fini(&msg->error);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Result__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Result * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ok
  if (lhs->ok != rhs->ok) {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Result__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Result * input,
  trajectory_loader__action__TrajectoryLoaderAction_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // ok
  output->ok = input->ok;
  // error
  if (!rosidl_runtime_c__String__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_Result *
trajectory_loader__action__TrajectoryLoaderAction_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Result * msg = (trajectory_loader__action__TrajectoryLoaderAction_Result *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Result__destroy(trajectory_loader__action__TrajectoryLoaderAction_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Result * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_Result *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_Result * data =
      (trajectory_loader__action__TrajectoryLoaderAction_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `trj_in_execution`
// Member `current_repetition`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(trajectory_loader__action__TrajectoryLoaderAction_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // trj_in_execution
  if (!rosidl_runtime_c__String__init(&msg->trj_in_execution)) {
    trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(msg);
    return false;
  }
  // current_repetition
  if (!rosidl_runtime_c__String__init(&msg->current_repetition)) {
    trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(trajectory_loader__action__TrajectoryLoaderAction_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // trj_in_execution
  rosidl_runtime_c__String__fini(&msg->trj_in_execution);
  // current_repetition
  rosidl_runtime_c__String__fini(&msg->current_repetition);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Feedback * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trj_in_execution
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->trj_in_execution), &(rhs->trj_in_execution)))
  {
    return false;
  }
  // current_repetition
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_repetition), &(rhs->current_repetition)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Feedback * input,
  trajectory_loader__action__TrajectoryLoaderAction_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // trj_in_execution
  if (!rosidl_runtime_c__String__copy(
      &(input->trj_in_execution), &(output->trj_in_execution)))
  {
    return false;
  }
  // current_repetition
  if (!rosidl_runtime_c__String__copy(
      &(input->current_repetition), &(output->current_repetition)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_Feedback *
trajectory_loader__action__TrajectoryLoaderAction_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Feedback * msg = (trajectory_loader__action__TrajectoryLoaderAction_Feedback *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Feedback__destroy(trajectory_loader__action__TrajectoryLoaderAction_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Feedback * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_Feedback *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_Feedback * data =
      (trajectory_loader__action__TrajectoryLoaderAction_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__init(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__init(&msg->goal)) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  trajectory_loader__action__TrajectoryLoaderAction_Goal__fini(&msg->goal);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * lhs, const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * input,
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!trajectory_loader__action__TrajectoryLoaderAction_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request *
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * msg = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__destroy(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request * data =
      (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__init(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * lhs, const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * input,
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response *
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * msg = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__destroy(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response * data =
      (trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__init(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * lhs, const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * input,
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request *
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * msg = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__destroy(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request * data =
      (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__init(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!trajectory_loader__action__TrajectoryLoaderAction_Result__init(&msg->result)) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  trajectory_loader__action__TrajectoryLoaderAction_Result__fini(&msg->result);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * lhs, const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!trajectory_loader__action__TrajectoryLoaderAction_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * input,
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!trajectory_loader__action__TrajectoryLoaderAction_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response *
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * msg = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__destroy(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response * data =
      (trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__functions.h"

bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__init(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__init(&msg->feedback)) {
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  trajectory_loader__action__TrajectoryLoaderAction_Feedback__fini(&msg->feedback);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * lhs, const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * input,
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!trajectory_loader__action__TrajectoryLoaderAction_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage *
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * msg = (trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage));
  bool success = trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__destroy(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__init(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * data = NULL;

  if (size) {
    data = (trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage *)allocator.zero_allocate(size, sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__fini(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence *
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * array = (trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence *)allocator.allocate(sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__destroy(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__are_equal(const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * lhs, const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence__copy(
  const trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * input,
  trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage * data =
      (trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
