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


void *helloworld_new(void)
{
  t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);
  int result;
  char *out_str;

  post("generating new helloworld object.");

  Py_Initialize();
  result = PyRun_SimpleString(
    "from time import time,ctime\n"
    "print('Today is',ctime(time())\n)"
  );

  out_str = (char*)malloc(100 * sizeof(char));
  sprintf(out_str, "result: %d", result);
  post(out_str);

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
