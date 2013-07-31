FLAGS = -g -std=c++11

all: fcm

fitness.o: fitness.cpp fitness.h
	g++ -c fitness.cpp $(FLAGS)

pso.o: pso.cpp pso.h fitness.o
	g++ -c pso.cpp $(FLAGS)

fcm: fcm.cpp fitness.o pso.o
	g++ -o fcm fitness.o pso.o fcm.cpp $(FLAGS)

clean:
	rm -f *.o fcm
