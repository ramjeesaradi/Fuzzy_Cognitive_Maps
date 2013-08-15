FLAGS = -g -std=c++11

all: train test

fcm.o: src/fcm.cpp src/fcm.h
	g++ -c -o obj/fcm.o src/fcm.cpp  $(FLAGS)

error.o: src/error.cpp src/error.h fcm.o
	g++ -c -o obj/error.o src/error.cpp  $(FLAGS)

pso.o: src/pso.cpp src/pso.h error.o fcm.o
	g++ -c -o obj/pso.o src/pso.cpp  $(FLAGS)

train: src/main.cpp error.o pso.o fcm.o
	g++ -o bin/train obj/error.o obj/pso.o obj/fcm.o src/main.cpp $(FLAGS)

test: src/test.cpp src/test.h fcm.o
	g++ -o bin/test obj/fcm.o src/test.cpp $(FLAGS)

clean:
	rm obj/*.o bin/*.exe
