#include <stdlib.h>
#include "m_pd.h"
#include "Python.h"


static t_class *runpython_class;


typedef struct _runpython {
  t_object  x_obj;
} t_runpython;


void runpython_bang(t_runpython *x) {
  post("I'm going to run a Python function call and print the result.");
}


char * getString(PyObject * obj) {
  PyObject *str_of_obj = PyObject_Str(obj);
  PyObject *temp_bytes = PyUnicode_AsEncodedString(str_of_obj, "UTF-8", "strict");
  char *str = PyBytes_AS_STRING(temp_bytes);
  // my_result = strdup(s1);  // from: <string.h>
  return str;
}


void *runpython_constructor(void) {
  PyObject *pName, *pModule;
  char *result_str;
  char *str_to_pd = (char*)malloc(100 * sizeof(char));

  t_runpython *obj = (t_runpython *)pd_new(runpython_class);  /* Parent's constructor */

  Py_Initialize();
  pName = PyUnicode_DecodeFSDefault("generate");
  result_str = getString(pName);
  sprintf(str_to_pd, "Going to load module: %s", result_str);
  post(str_to_pd);

  pModule = PyImport_Import(pName);

  if (pModule != NULL) {
  }
  else {
    PyErr_Print();
    post("Failed to load module.");
  }

  return (void *)obj;
}


void runpython_setup(void) {
  /* class_new(object_name, constructor_function, destructor_function, object_data_space_size, object_type, creation_arguments) */
  runpython_class = class_new(
    gensym("runpython"),
    (t_newmethod)runpython_constructor,
    0,
    sizeof(t_runpython),
    CLASS_DEFAULT,
    0
  );

  class_addbang(runpython_class, runpython_bang);
}
