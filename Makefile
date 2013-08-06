FLAGS = -g -std=c++11

all: main.exe test.exe

fcm.o: fcm.cpp fcm.h
	g++ -c fcm.cpp $(FLAGS)

error.o: error.cpp error.h fcm.o
	g++ -c error.cpp $(FLAGS)

pso.o: pso.cpp pso.h error.o fcm.o
	g++ -c pso.cpp $(FLAGS)

main.exe: main.cpp error.o pso.o fcm.o
	g++ -o main.exe error.o pso.o fcm.o main.cpp $(FLAGS)

test.exe: test.cpp
	g++ -o test.exe test.cpp $(FLAGS)

clean:
	rm -f *.o main
