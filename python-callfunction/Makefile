TARGET=32

ifeq ($(TARGET),32)
	CC = "c:/mingw/bin/gcc.exe"
	INCLUDE = -I "c:/Users/veliu/Miniconda3/include"
	LIBS = -L "c:/Users/veliu/Miniconda3/libs"
	LIBRARIES = -lpython36
endif
ifeq ($(TARGET),64)
	CC = "C:/mingw-w64/mingw64/bin/gcc.exe"
	INCLUDE = -I "c:/Users/veliu/Anaconda3/include"
	LIBS = -L "c:/Users/veliu/Anaconda3/libs"
	LIBRARIES = -lpython35
endif

all:
	$(CC) $(INCLUDE) $(LIBS) -o call.exe call.c $(LIBRARIES)

clean:
	rm call.exe
