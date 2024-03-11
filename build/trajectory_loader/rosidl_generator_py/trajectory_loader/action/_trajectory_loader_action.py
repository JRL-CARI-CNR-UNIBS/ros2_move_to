# generated from rosidl_generator_py/resource/_idl.py.em
# with input from trajectory_loader:action/TrajectoryLoaderAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TrajectoryLoaderAction_Goal(type):
    """Metaclass of message 'TrajectoryLoaderAction_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_Goal(metaclass=Metaclass_TrajectoryLoaderAction_Goal):
    """Message class 'TrajectoryLoaderAction_Goal'."""

    __slots__ = [
        '_group_name',
        '_trj_names',
        '_repetitions',
        '_rescale',
        '_simulation',
    ]

    _fields_and_field_types = {
        'group_name': 'string',
        'trj_names': 'sequence<string>',
        'repetitions': 'int32',
        'rescale': 'boolean',
        'simulation': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.group_name = kwargs.get('group_name', str())
        self.trj_names = kwargs.get('trj_names', [])
        self.repetitions = kwargs.get('repetitions', int())
        self.rescale = kwargs.get('rescale', bool())
        self.simulation = kwargs.get('simulation', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.group_name != other.group_name:
            return False
        if self.trj_names != other.trj_names:
            return False
        if self.repetitions != other.repetitions:
            return False
        if self.rescale != other.rescale:
            return False
        if self.simulation != other.simulation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def group_name(self):
        """Message field 'group_name'."""
        return self._group_name

    @group_name.setter
    def group_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'group_name' field must be of type 'str'"
        self._group_name = value

    @builtins.property
    def trj_names(self):
        """Message field 'trj_names'."""
        return self._trj_names

    @trj_names.setter
    def trj_names(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'trj_names' field must be a set or sequence and each value of type 'str'"
        self._trj_names = value

    @builtins.property
    def repetitions(self):
        """Message field 'repetitions'."""
        return self._repetitions

    @repetitions.setter
    def repetitions(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'repetitions' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'repetitions' field must be an integer in [-2147483648, 2147483647]"
        self._repetitions = value

    @builtins.property
    def rescale(self):
        """Message field 'rescale'."""
        return self._rescale

    @rescale.setter
    def rescale(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'rescale' field must be of type 'bool'"
        self._rescale = value

    @builtins.property
    def simulation(self):
        """Message field 'simulation'."""
        return self._simulation

    @simulation.setter
    def simulation(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'simulation' field must be of type 'bool'"
        self._simulation = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_Result(type):
    """Metaclass of message 'TrajectoryLoaderAction_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_Result(metaclass=Metaclass_TrajectoryLoaderAction_Result):
    """Message class 'TrajectoryLoaderAction_Result'."""

    __slots__ = [
        '_ok',
        '_error',
    ]

    _fields_and_field_types = {
        'ok': 'boolean',
        'error': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ok = kwargs.get('ok', bool())
        self.error = kwargs.get('error', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.ok != other.ok:
            return False
        if self.error != other.error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ok(self):
        """Message field 'ok'."""
        return self._ok

    @ok.setter
    def ok(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'ok' field must be of type 'bool'"
        self._ok = value

    @builtins.property
    def error(self):
        """Message field 'error'."""
        return self._error

    @error.setter
    def error(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error' field must be of type 'str'"
        self._error = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_Feedback(type):
    """Metaclass of message 'TrajectoryLoaderAction_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_Feedback(metaclass=Metaclass_TrajectoryLoaderAction_Feedback):
    """Message class 'TrajectoryLoaderAction_Feedback'."""

    __slots__ = [
        '_trj_in_execution',
        '_current_repetition',
    ]

    _fields_and_field_types = {
        'trj_in_execution': 'string',
        'current_repetition': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.trj_in_execution = kwargs.get('trj_in_execution', str())
        self.current_repetition = kwargs.get('current_repetition', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.trj_in_execution != other.trj_in_execution:
            return False
        if self.current_repetition != other.current_repetition:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def trj_in_execution(self):
        """Message field 'trj_in_execution'."""
        return self._trj_in_execution

    @trj_in_execution.setter
    def trj_in_execution(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'trj_in_execution' field must be of type 'str'"
        self._trj_in_execution = value

    @builtins.property
    def current_repetition(self):
        """Message field 'current_repetition'."""
        return self._current_repetition

    @current_repetition.setter
    def current_repetition(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'current_repetition' field must be of type 'str'"
        self._current_repetition = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_SendGoal_Request(type):
    """Metaclass of message 'TrajectoryLoaderAction_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__send_goal__request

            from trajectory_loader.action import TrajectoryLoaderAction
            if TrajectoryLoaderAction.Goal.__class__._TYPE_SUPPORT is None:
                TrajectoryLoaderAction.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_SendGoal_Request(metaclass=Metaclass_TrajectoryLoaderAction_SendGoal_Request):
    """Message class 'TrajectoryLoaderAction_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'trajectory_loader/TrajectoryLoaderAction_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trajectory_loader', 'action'], 'TrajectoryLoaderAction_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Goal
        self.goal = kwargs.get('goal', TrajectoryLoaderAction_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Goal
            assert \
                isinstance(value, TrajectoryLoaderAction_Goal), \
                "The 'goal' field must be a sub message of type 'TrajectoryLoaderAction_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_SendGoal_Response(type):
    """Metaclass of message 'TrajectoryLoaderAction_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_SendGoal_Response(metaclass=Metaclass_TrajectoryLoaderAction_SendGoal_Response):
    """Message class 'TrajectoryLoaderAction_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_TrajectoryLoaderAction_SendGoal(type):
    """Metaclass of service 'TrajectoryLoaderAction_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__trajectory_loader_action__send_goal

            from trajectory_loader.action import _trajectory_loader_action
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal_Request._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal_Request.__import_type_support__()
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal_Response._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal_Response.__import_type_support__()


class TrajectoryLoaderAction_SendGoal(metaclass=Metaclass_TrajectoryLoaderAction_SendGoal):
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_SendGoal_Request as Request
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_GetResult_Request(type):
    """Metaclass of message 'TrajectoryLoaderAction_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_GetResult_Request(metaclass=Metaclass_TrajectoryLoaderAction_GetResult_Request):
    """Message class 'TrajectoryLoaderAction_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_GetResult_Response(type):
    """Metaclass of message 'TrajectoryLoaderAction_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__get_result__response

            from trajectory_loader.action import TrajectoryLoaderAction
            if TrajectoryLoaderAction.Result.__class__._TYPE_SUPPORT is None:
                TrajectoryLoaderAction.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_GetResult_Response(metaclass=Metaclass_TrajectoryLoaderAction_GetResult_Response):
    """Message class 'TrajectoryLoaderAction_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'trajectory_loader/TrajectoryLoaderAction_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trajectory_loader', 'action'], 'TrajectoryLoaderAction_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Result
        self.result = kwargs.get('result', TrajectoryLoaderAction_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Result
            assert \
                isinstance(value, TrajectoryLoaderAction_Result), \
                "The 'result' field must be a sub message of type 'TrajectoryLoaderAction_Result'"
        self._result = value


class Metaclass_TrajectoryLoaderAction_GetResult(type):
    """Metaclass of service 'TrajectoryLoaderAction_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__trajectory_loader_action__get_result

            from trajectory_loader.action import _trajectory_loader_action
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult_Request._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult_Request.__import_type_support__()
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult_Response._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult_Response.__import_type_support__()


class TrajectoryLoaderAction_GetResult(metaclass=Metaclass_TrajectoryLoaderAction_GetResult):
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_GetResult_Request as Request
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_TrajectoryLoaderAction_FeedbackMessage(type):
    """Metaclass of message 'TrajectoryLoaderAction_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__trajectory_loader_action__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__trajectory_loader_action__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__trajectory_loader_action__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__trajectory_loader_action__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__trajectory_loader_action__feedback_message

            from trajectory_loader.action import TrajectoryLoaderAction
            if TrajectoryLoaderAction.Feedback.__class__._TYPE_SUPPORT is None:
                TrajectoryLoaderAction.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TrajectoryLoaderAction_FeedbackMessage(metaclass=Metaclass_TrajectoryLoaderAction_FeedbackMessage):
    """Message class 'TrajectoryLoaderAction_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'trajectory_loader/TrajectoryLoaderAction_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trajectory_loader', 'action'], 'TrajectoryLoaderAction_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Feedback
        self.feedback = kwargs.get('feedback', TrajectoryLoaderAction_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Feedback
            assert \
                isinstance(value, TrajectoryLoaderAction_Feedback), \
                "The 'feedback' field must be a sub message of type 'TrajectoryLoaderAction_Feedback'"
        self._feedback = value


class Metaclass_TrajectoryLoaderAction(type):
    """Metaclass of action 'TrajectoryLoaderAction'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trajectory_loader')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trajectory_loader.action.TrajectoryLoaderAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__trajectory_loader_action

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from trajectory_loader.action import _trajectory_loader_action
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_SendGoal.__import_type_support__()
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_GetResult.__import_type_support__()
            if _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_FeedbackMessage._TYPE_SUPPORT is None:
                _trajectory_loader_action.Metaclass_TrajectoryLoaderAction_FeedbackMessage.__import_type_support__()


class TrajectoryLoaderAction(metaclass=Metaclass_TrajectoryLoaderAction):

    # The goal message defined in the action definition.
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Goal as Goal
    # The result message defined in the action definition.
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Result as Result
    # The feedback message defined in the action definition.
    from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from trajectory_loader.action._trajectory_loader_action import TrajectoryLoaderAction_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
