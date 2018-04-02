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

# Build, Install

- `cd C:\Users\veliu\Documents\repos\puredata-python\pd-python-object`
- `mingw32-make.exe clean` deletes existing `.o` and `.dll` files
- `mingw32-make.exe` compiles, links and generate `runpython.dll`
- `mingw32-make.exe install` copies `runpython.dll` to Pure Data's externals folders


# Run

- `cd C:\Users\veliu\Documents\repos\puredata-python\pd-python-object`
- `SET PATH=C:\Users\veliu\Miniconda3;%PATH%` (?)
- `SET PYTHONHOME=C:\Users\veliu\Miniconda3` Make Miniconda's main environment system's Python
- `c:\Users\veliu\Downloads\pd\bin\pd.exe` Run Pure Data from project folder (?)
- open `test_runpython.pd`
- Send `bang` message to `runpython` object
