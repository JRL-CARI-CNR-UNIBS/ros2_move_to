// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from trajectory_loader:action/TrajectoryLoaderAction.idl
// generated code does not contain a copyright notice

#ifndef TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_HPP_
#define TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Goal __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Goal __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_Goal_
{
  using Type = TrajectoryLoaderAction_Goal_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
      this->repetitions = 0l;
      this->rescale = false;
      this->simulation = false;
    }
  }

  explicit TrajectoryLoaderAction_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : group_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->group_name = "";
      this->repetitions = 0l;
      this->rescale = false;
      this->simulation = false;
    }
  }

  // field types and members
  using _group_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _group_name_type group_name;
  using _trj_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _trj_names_type trj_names;
  using _repetitions_type =
    int32_t;
  _repetitions_type repetitions;
  using _rescale_type =
    bool;
  _rescale_type rescale;
  using _simulation_type =
    bool;
  _simulation_type simulation;

  // setters for named parameter idiom
  Type & set__group_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->group_name = _arg;
    return *this;
  }
  Type & set__trj_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->trj_names = _arg;
    return *this;
  }
  Type & set__repetitions(
    const int32_t & _arg)
  {
    this->repetitions = _arg;
    return *this;
  }
  Type & set__rescale(
    const bool & _arg)
  {
    this->rescale = _arg;
    return *this;
  }
  Type & set__simulation(
    const bool & _arg)
  {
    this->simulation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Goal
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Goal
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_Goal_ & other) const
  {
    if (this->group_name != other.group_name) {
      return false;
    }
    if (this->trj_names != other.trj_names) {
      return false;
    }
    if (this->repetitions != other.repetitions) {
      return false;
    }
    if (this->rescale != other.rescale) {
      return false;
    }
    if (this->simulation != other.simulation) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_Goal_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_Goal =
  trajectory_loader::action::TrajectoryLoaderAction_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader


#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Result __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Result __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_Result_
{
  using Type = TrajectoryLoaderAction_Result_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ok = false;
      this->error = "";
    }
  }

  explicit TrajectoryLoaderAction_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ok = false;
      this->error = "";
    }
  }

  // field types and members
  using _ok_type =
    bool;
  _ok_type ok;
  using _error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _error_type error;

  // setters for named parameter idiom
  Type & set__ok(
    const bool & _arg)
  {
    this->ok = _arg;
    return *this;
  }
  Type & set__error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Result
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Result
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_Result_ & other) const
  {
    if (this->ok != other.ok) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_Result_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_Result =
  trajectory_loader::action::TrajectoryLoaderAction_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader


#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Feedback __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_Feedback_
{
  using Type = TrajectoryLoaderAction_Feedback_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trj_in_execution = "";
      this->current_repetition = "";
    }
  }

  explicit TrajectoryLoaderAction_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trj_in_execution(_alloc),
    current_repetition(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trj_in_execution = "";
      this->current_repetition = "";
    }
  }

  // field types and members
  using _trj_in_execution_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _trj_in_execution_type trj_in_execution;
  using _current_repetition_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_repetition_type current_repetition;

  // setters for named parameter idiom
  Type & set__trj_in_execution(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->trj_in_execution = _arg;
    return *this;
  }
  Type & set__current_repetition(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_repetition = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Feedback
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_Feedback
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_Feedback_ & other) const
  {
    if (this->trj_in_execution != other.trj_in_execution) {
      return false;
    }
    if (this->current_repetition != other.current_repetition) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_Feedback_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_Feedback =
  trajectory_loader::action::TrajectoryLoaderAction_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "trajectory_loader/action/detail/trajectory_loader_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_SendGoal_Request_
{
  using Type = TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit TrajectoryLoaderAction_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const trajectory_loader::action::TrajectoryLoaderAction_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Request
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_SendGoal_Request_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_SendGoal_Request =
  trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_SendGoal_Response_
{
  using Type = TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit TrajectoryLoaderAction_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_SendGoal_Response
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_SendGoal_Response_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_SendGoal_Response =
  trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader

namespace trajectory_loader
{

namespace action
{

struct TrajectoryLoaderAction_SendGoal
{
  using Request = trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Request;
  using Response = trajectory_loader::action::TrajectoryLoaderAction_SendGoal_Response;
};

}  // namespace action

}  // namespace trajectory_loader


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_GetResult_Request_
{
  using Type = TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit TrajectoryLoaderAction_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Request
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_GetResult_Request_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_GetResult_Request =
  trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader


// Include directives for member types
// Member 'result'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_GetResult_Response_
{
  using Type = TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit TrajectoryLoaderAction_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const trajectory_loader::action::TrajectoryLoaderAction_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_GetResult_Response
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_GetResult_Response_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_GetResult_Response =
  trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader

namespace trajectory_loader
{

namespace action
{

struct TrajectoryLoaderAction_GetResult
{
  using Request = trajectory_loader::action::TrajectoryLoaderAction_GetResult_Request;
  using Response = trajectory_loader::action::TrajectoryLoaderAction_GetResult_Response;
};

}  // namespace action

}  // namespace trajectory_loader


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "trajectory_loader/action/detail/trajectory_loader_action__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage __declspec(deprecated)
#endif

namespace trajectory_loader
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct TrajectoryLoaderAction_FeedbackMessage_
{
  using Type = TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>;

  explicit TrajectoryLoaderAction_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit TrajectoryLoaderAction_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const trajectory_loader::action::TrajectoryLoaderAction_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__trajectory_loader__action__TrajectoryLoaderAction_FeedbackMessage
    std::shared_ptr<trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryLoaderAction_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryLoaderAction_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryLoaderAction_FeedbackMessage_

// alias to use template instance with default allocator
using TrajectoryLoaderAction_FeedbackMessage =
  trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace trajectory_loader

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace trajectory_loader
{

namespace action
{

struct TrajectoryLoaderAction
{
  /// The goal message defined in the action definition.
  using Goal = trajectory_loader::action::TrajectoryLoaderAction_Goal;
  /// The result message defined in the action definition.
  using Result = trajectory_loader::action::TrajectoryLoaderAction_Result;
  /// The feedback message defined in the action definition.
  using Feedback = trajectory_loader::action::TrajectoryLoaderAction_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = trajectory_loader::action::TrajectoryLoaderAction_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = trajectory_loader::action::TrajectoryLoaderAction_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = trajectory_loader::action::TrajectoryLoaderAction_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct TrajectoryLoaderAction TrajectoryLoaderAction;

}  // namespace action

}  // namespace trajectory_loader

#endif  // TRAJECTORY_LOADER__ACTION__DETAIL__TRAJECTORY_LOADER_ACTION__STRUCT_HPP_
