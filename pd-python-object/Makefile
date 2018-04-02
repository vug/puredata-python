BIT=32
PDDIST=vanilla

# Vanilla Pure Data
ifeq ($(PDDIST),vanilla)
	PDPATH = C:/Users/veliu/Downloads/pd
	PDINCLUDE = -I "$(PDPATH)/src"
endif
# Purr Data
ifeq ($(PDDIST),purr)
  PDPATH = C:/Program Files (x86)/Purr Data
	PDINCLUDE = -I "$(PDPATH)/include"
endif
PDEXTERNALS = C:/Users/veliu/Documents/Pd/externals

ifeq ($(BIT),32)
	CC = "c:/mingw/bin/gcc.exe"
	PYTHONINCLUDE = -I "c:/Users/veliu/Miniconda3/include"
	PYTHONLIBSPATH = -L "c:/Users/veliu/Miniconda3/libs"
	PYTHONLIBRARIES = -lpython36
endif
ifeq ($(BIT),64)
	CC = "C:/mingw-w64/mingw64/bin/gcc.exe"
	PYTHONINCLUDE = -I "c:/Users/veliu/Anaconda3/include"
	PYTHONLIBSPATH = -L "c:/Users/veliu/Anaconda3/libs"
	PYTHONLIBRARIES = -lpython35
endif

EXTERNALNAME = runpython
INCLUDE = $(PDINCLUDE) $(PYTHONINCLUDE)
LIBRARIES = $(PYTHONLIBRARIES) -lmsvcrt
LDLAGS = --export-all-symbols -shared

all: $(EXTERNALNAME).dll

$(EXTERNALNAME).dll: main.o
	ld $(LDLAGS) $(PYTHONLIBSPATH) -o $(EXTERNALNAME).dll main.o "$(PDPATH)/bin/pd.dll" $(LIBRARIES)
	strip --strip-unneeded $(EXTERNALNAME).dll

main.o: main.c
	gcc $(INCLUDE) -c main.c -o main.o

clean:
	rm main.o $(EXTERNALNAME).dll

install:
	cp $(EXTERNALNAME).dll $(PDEXTERNALS)

uninstall:
	cd $(PDEXTERNALS) && rm $(EXTERNALNAME).dll
