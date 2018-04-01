#include "m_pd.h"


static t_class *runpython_class;


typedef struct _runpython {
  t_object  x_obj;
} t_runpython;


void runpython_bang(t_runpython *x) {
  post("I'm going to run a Python function call and print the result.");
}


void *runpython_constructor(void) {
  t_runpython *obj = (t_runpython *)pd_new(runpython_class);  /* Parent's constructor */

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
