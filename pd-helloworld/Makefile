# Vanilla Pure Data
PDPATH = C:/Users/veliu/Downloads/pd
INCLUDE = -I "$(PDPATH)/src"

# Purr Data
ifeq ($(TARGET),purr)
  PDPATH = C:/Program Files (x86)/Purr Data
	INCLUDE = -I "$(PDPATH)/include"
endif

# WINDOWS
LDFLAGS = --export-all-symbols -shared
DLLS = "$(PDPATH)/bin/pd.dll"

all: helloworld.dll

helloworld.dll: helloworld.o
	ld $(LDFLAGS) -o helloworld.dll helloworld.o $(DLLS)
	strip --strip-unneeded helloworld.dll

helloworld.o: helloworld.c
	gcc $(INCLUDE) -c helloworld.c -o helloworld.o

clean:
	rm helloworld.o helloworld.dll
