PDPATH = /Applications/Pd-0.48-1.app/Contents/Resources
ANACONDAPATH = /Users/ugur/anaconda3
INCLUDE = -I $(PDPATH)/src -I $(ANACONDAPATH)/include/python3.5m -I $(ANACONDAPATH)/include
LIBRARIES = -lpython3.5m -ldl
# LIBRARIES = -lpython3.5m -ldl -framework CoreFoundation

LIBEXTENSION = pd_darwin
LDFLAGS = -undefined suppress -flat_namespace -bundle
SHAREDFLAGS = -undefined dynamic_lookup
# VERFLAGS = -macosx_version_min 10.12
EXTERNALS = /Users/ugur/Documents/Pd/externals

all:
	gcc $(INCLUDE) -o helloworld.o -c main.c
	# clang -L/Users/ugur/anaconda3/lib $(LIBRARIES) $(LDFLAGS) $(SHAREDFLAGS) $(VERFLAGS) -o helloworld.pd_darwin helloworld.o
	clang -L/Users/ugur/anaconda3/lib $(LIBRARIES) $(LDFLAGS) $(SHAREDFLAGS) -o helloworld.pd_darwin helloworld.o

# helloworld.$(LIBEXTENSION): helloworld.o
# 	ld $(LDFLAGS) $(SHAREDFLAGS) $(VERFLAGS) -o helloworld.$(LIBEXTENSION) helloworld.o
#
# helloworld.o: main.c
# 	clang $(INCLUDE) -c main.c -o helloworld.o
#
# clean:
# 	rm helloworld.o helloworld.$(LIBEXTENSION)
#
install:
	cp helloworld.$(LIBEXTENSION) $(EXTERNALS)

# uninstall:
# 	cd $(EXTERNALS) && rm helloworld.$(LIBEXTENSION)
