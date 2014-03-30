CPP=g++
CFLAGS=-I. -I /usr/local/include
LFLAGS=-lGL -lGLEW -L/usr/local/lib/ -lglfw

all:
	$(CPP) first.cpp $(CFLAGS) $(LFLAGS) -o first
