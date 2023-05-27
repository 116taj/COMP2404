OBJ = Date.o Room.o Reservation.o Hotel.o main.o

all: a1

a1: $(OBJ) 
	g++ -o a1 $(OBJ) 

Date.o: Date.h Date.cc
	g++ -c Date.cc

Room.o: Room.h defs.h Room.cc
	g++ -c Room.cc	

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Hotel.o: Hotel.h defs.h Hotel.cc 
	g++ -c Hotel.cc	

main.o: main.cc
	g++ -c main.cc

clean:
	rm -f a1 $(OBJ) 
