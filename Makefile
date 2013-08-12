FLAGS = -g -std=c++11

all: main.exe test.exe

fcm.o: src/fcm.cpp src/fcm.h
	g++ -c obj/fcm.o src/fcm.cpp $(FLAGS)

error.o: src/error.cpp src/error.h obj/fcm.o
	g++ -c obj/error.o src/error.cpp $(FLAGS)

pso.o: src/pso.cpp src/pso.h obj/error.o obj/fcm.o
	g++ -c obj/pso.o src/pso.cpp $(FLAGS)

main.exe: src/main.cpp obj/error.o obj/pso.o obj/fcm.o
	g++ -o bin/main.exe obj/error.o obj/pso.o obj/fcm.o src/main.cpp $(FLAGS)

test.exe: src/test.cpp src/test.h obj/fcm.o
	g++ -o bin/test.exe obj/fcm.o src/test.cpp $(FLAGS)

clean:
	rm -f obj/*.o main