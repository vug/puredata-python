# runpython

A Pure Data object that calls Python functions by running them on system's Python interpreter.

say we have a Python module `generate.py`

```python
import random
def get_random_note():
    return random.randint(1, 7)
```

Create Pure Data object `runpython` and send `bang` messages:

![screenshot](https://i.imgur.com/eggdGAZ.png)
