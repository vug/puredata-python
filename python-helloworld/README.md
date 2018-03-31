# A "Hello World" example for embedding Python in

## 32-bit version

I have a 32-bit Python 3.6 installed via Miniconda3, and a 32-bit gcc via MinGW

Build

- `mingw32-make.exe` uses 32-bit MinGW

Run

- `SET PATH=C:\Users\veliu\Miniconda3;%PATH%` temporarily set Miniconda path higher priority than existing Anaconda
- `SET PYTHONHOME=C:\Users\veliu\Miniconda3`
- `helloworld.exe`

## 64-bit version

This one is a bit weird. I have a 64-bit Python 3.5 installed via Anaconda3, and a 64-bit gcc via MinGW64

Build

In order to build first a MinGW64 console has to run.

- Open `Cmder`
- `c:\mingw-w64\mingw-w64.bat` runs MinGW64 console inside console
- `cd c:\Users\veliu\Documents\repos\puredata-python\python-helloworld`
- `c:\MinGW\bin\mingw32-make.exe TARGET=64` apparently, the bit-ness of make doesn't have an effect

Run

Apparently, Anaconda is already has the path, and correct PYTHONHOME setting.

- `helloworld.exe`
