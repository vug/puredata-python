#include <stdlib.h>
#include "m_pd.h"
#include "Python.h"

static t_class *helloworld_class;


typedef struct _helloworld {
  t_object  x_obj;
} t_helloworld;


void helloworld_bang(t_helloworld *x)
{
  post("Hello world !!");
}

char * getString(PyObject * obj) {
  PyObject *str_of_obj = PyObject_Str(obj);
  PyObject *temp_bytes = PyUnicode_AsEncodedString(str_of_obj, "UTF-8", "strict");
  char *str = PyBytes_AS_STRING(temp_bytes);
  // my_result = strdup(s1);  // from: <string.h>
  return str;
}


void *helloworld_new(void)
{
  t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);
  int runState;
  char *str_to_pd = (char*)malloc(100 * sizeof(char));
  char *result_str;
  PyObject* locals = PyDict_New();
  PyObject* globals = PyDict_New();
  PyObject* resultObject;

  post("generating new helloworld object...");

  Py_Initialize();

  PyMapping_SetItemString(globals, "time", PyImport_ImportModule("time"));
  resultObject = PyRun_String(
    "time.ctime(time.time())\n",
     Py_eval_input,
     locals,
     globals
  );
  result_str = getString(resultObject);
  sprintf(str_to_pd, "PyRun_String result: %s", result_str);
  post(str_to_pd);

  return (void *)x;
}


void helloworld_setup(void) {
  helloworld_class = class_new(gensym("helloworld"),        /* the object's name is "helloworld" */
			       (t_newmethod)helloworld_new, /* the object's constructor is "helloworld_new()" */
			       0,                           /* no special destructor */
			       sizeof(t_helloworld),        /* the size of the data-space */
			       CLASS_DEFAULT,               /* a normal pd object */
			       0);                          /* no creation arguments */

  class_addbang(helloworld_class, helloworld_bang);
}
