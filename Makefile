FLAGS = -g -std=c++11

all: fcm.exe

fitness.o: fitness.cpp fitness.h
	g++ -c fitness.cpp $(FLAGS)

pso.o: pso.cpp pso.h fitness.o
	g++ -c pso.cpp $(FLAGS)

fcm.exe: fcm.cpp fitness.o pso.o
	g++ -o fcm.exe fitness.o pso.o fcm.cpp $(FLAGS)

clean:
	rm -f *.o fcm
