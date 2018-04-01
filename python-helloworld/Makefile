CC = clang
CFLAGS = -arch x86_64 -g
INCLUDE = -I/Users/ugur/anaconda3/include/python3.5m -I/Users/ugur/anaconda3/include
LIBS = -lpython3.5m -ldl -framework CoreFoundation

all:
	gcc $(INCLUDE) -o helloworld.o -c helloworld.c
	clang -L/Users/ugur/anaconda3/lib $(LIBS) -o helloworld helloworld.o

clean:
	rm helloworld
