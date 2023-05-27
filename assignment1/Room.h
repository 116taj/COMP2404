
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"
#include "defs.h"

using namespace std;

class Room {
		
	public:
		//constructors
		Room(int, string, int, bool);
		//destructor
		~Room();
        //getters
        int getRoomNumber();
		//check if room number is less than another room number
		bool lessThan(Room& room);
		//checks if this room matches the contraints given in the parameters
        bool isMatch(string, int, bool);
		//adds a reservation to the room, if possible
		bool addReservation(string,Date&,int);		
		//removes reservations for room if the checkIn date has passed 
		void updateReservations(Date&);
		//prints room
		void print();
		//prints room + reservations
		void printReservations();
	private:
		//variables
		int roomNumber;
		string bedType;
		int capacity;
        bool hasFridge;
        Reservation* reservations[MAX_RES];
        int reservationCount;
};
#endif
