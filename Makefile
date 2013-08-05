FLAGS = -g -std=c++11

all: fcm.exe test.exe

error.o: error.cpp error.h
	g++ -c error.cpp $(FLAGS)

pso.o: pso.cpp pso.h error.o
	g++ -c pso.cpp $(FLAGS)

fcm.exe: fcm.cpp error.o pso.o
	g++ -o fcm.exe error.o pso.o fcm.cpp $(FLAGS)

test.exe: test.cpp
	g++ -o test.exe test.cpp $(FLAGS)

clean:
	rm -f *.o fcm
