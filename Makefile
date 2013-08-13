FLAGS = -g -std=c++11

all: main.exe test.exe

fcm.o: src/fcm.cpp src/fcm.h
	g++ -c src/fcm.cpp  $(FLAGS)

error.o: src/error.cpp src/error.h fcm.o
	g++ -c  src/error.cpp  $(FLAGS)

pso.o: src/pso.cpp src/pso.h error.o fcm.o
	g++ -c src/pso.cpp  $(FLAGS)

main.exe: src/main.cpp error.o pso.o fcm.o
	g++ -o bin/main.exe error.o pso.o fcm.o src/main.cpp $(FLAGS)

test.exe: src/test.cpp src/test.h fcm.o
	g++ -o bin/test.exe fcm.o src/test.cpp $(FLAGS)

clean:
	rm -f /*.o main