#include <stdlib.h>
#include "m_pd.h"
#include "Python.h"

char * getString(PyObject * obj);

static t_class *runpython_class;


typedef struct _runpython {
  t_object x_obj;
  PyObject* pModule;
} t_runpython;


void runpython_bang(t_runpython *obj) {
  if(obj->pModule == NULL) {
    post("Object banged automatically while being created. Python module not loaded yet. Not going to call.");
    return;
  }
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
  PyObject* locals = PyDict_New();
  PyObject* globals = PyDict_New();
  PyObject* resultObject;
  PyObject* sysPath;

  PyObject* pX;

  t_runpython *obj = (t_runpython *)pd_new(runpython_class);  /* Parent's constructor */

  Py_Initialize();
  // Add current directory (from where we call the pd.exe) to Python's sys.path
  // so that import statement can find the module if it is located in the same directory
  sysPath = PySys_GetObject((char*)"path");
  PyList_Append(sysPath, PyUnicode_DecodeFSDefault("."));

  PyMapping_SetItemString(globals, "os", PyImport_ImportModule("os"));
  resultObject = PyRun_String(
    "os.getcwd()\n",
    Py_eval_input, locals, globals
  );
  result_str = getString(resultObject);
  sprintf(str_to_pd, "os.getcwd(): %s", result_str);
  post(str_to_pd);

  pName = PyUnicode_DecodeFSDefault("generate");
  result_str = getString(pName);
  sprintf(str_to_pd, "Going to load module: %s", result_str);
  post(str_to_pd);

  obj->pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  if (obj->pModule == NULL) {
    PyErr_Print();
    post("Failed to load module.");
    return (void *)obj;
  }

  post("Module loaded.");
  pX = PyObject_GetAttrString(obj->pModule, "x");
  result_str = getString(pX);
  sprintf(str_to_pd, "x = %s", result_str);
  post(str_to_pd);

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
