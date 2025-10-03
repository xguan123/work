// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cpp_pubsub:msg/Signal.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cpp_pubsub/msg/detail/signal__struct.h"
#include "cpp_pubsub/msg/detail/signal__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cpp_pubsub__msg__signal__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[30];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cpp_pubsub.msg._signal.Signal", full_classname_dest, 29) == 0);
  }
  cpp_pubsub__msg__Signal * ros_message = _ros_message;
  {  // sine_wave
    PyObject * field = PyObject_GetAttrString(_pymsg, "sine_wave");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sine_wave = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // square_wave
    PyObject * field = PyObject_GetAttrString(_pymsg, "square_wave");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->square_wave = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cpp_pubsub__msg__signal__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Signal */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cpp_pubsub.msg._signal");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Signal");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cpp_pubsub__msg__Signal * ros_message = (cpp_pubsub__msg__Signal *)raw_ros_message;
  {  // sine_wave
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sine_wave);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sine_wave", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // square_wave
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->square_wave);
    {
      int rc = PyObject_SetAttrString(_pymessage, "square_wave", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
