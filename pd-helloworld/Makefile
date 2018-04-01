PDPATH = /Applications/Pd-0.48-1.app/Contents/Resources
INCLUDE = -I $(PDPATH)/src

LIBEXTENSION = pd_darwin
LDFLAGS = -undefined suppress -flat_namespace -bundle
SHAREDFLAGS = -undefined dynamic_lookup
VERFLAGS = -macosx_version_min 10.12
EXTERNALS = /Users/ugur/Documents/Pd/externals

all: helloworld.$(LIBEXTENSION)

helloworld.$(LIBEXTENSION): helloworld.o
	ld $(LDFLAGS) $(SHAREDFLAGS) $(VERFLAGS) -o helloworld.$(LIBEXTENSION) helloworld.o

helloworld.o: helloworld.c
	clang $(INCLUDE) -c helloworld.c -o helloworld.o

clean:
	rm helloworld.o helloworld.$(LIBEXTENSION)

install:
	cp helloworld.$(LIBEXTENSION) $(EXTERNALS)

uninstall:
	cd $(EXTERNALS) && rm helloworld.$(LIBEXTENSION)
