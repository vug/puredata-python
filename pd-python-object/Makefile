EXTERNALNAME = runpython

# Vanilla Pure Data
PDPATH = C:/Users/veliu/Downloads/pd
INCLUDE = -I "$(PDPATH)/src"

# Purr Data
ifeq ($(TARGET),purr)
  PDPATH = C:/Program Files (x86)/Purr Data
	INCLUDE = -I "$(PDPATH)/include"
endif

WINLDFLAGS = --export-all-symbols -shared
LDLAGS = $(WINLDFLAGS)
DLLS = "$(PDPATH)/bin/pd.dll"
EXTRA = "$(PDPATH)/extra"

all: $(EXTERNALNAME).dll

$(EXTERNALNAME).dll: $(EXTERNALNAME).o
	ld $(LDFLAGS) -o $(EXTERNALNAME).dll $(EXTERNALNAME).o $(DLLS)
	strip --strip-unneeded $(EXTERNALNAME).dll

$(EXTERNALNAME).o: main.c
	gcc $(INCLUDE) -c main.c -o $(EXTERNALNAME).o

clean:
	rm $(EXTERNALNAME).o $(EXTERNALNAME).dll

install:
	cp $(EXTERNALNAME).dll $(EXTRA)

uninstall:
	cd $(EXTRA) && rm $(EXTERNALNAME).dll
