
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Room.h"
#include "defs.h"

using namespace std;

class Hotel {
		
	public:
		//constructors
		Hotel();
		//destructor
		~Hotel();
        //getters
        //get room by number
        bool getRoom(int, Room**);
        //add room to hotel
        bool addRoom(int roomNum, string bedType, int capacity, bool hasFridge);
        //remove room from hotel
		bool deleteRoom(int roomNum);
        //add a reservation to the hotel so long as a room matches requirements and is available
		bool addReservation(string custName,string bedType,int capacity, bool hasFridge ,Date& date,int duration);	
        //remove reservations that occur before currentDate
        void updateReservations(Date& currentDate);	
        //print hotel
		void print();
        //print hotel + reservations 
		void printReservations();
	private:
		//variables
        Room* rooms[MAX_ROOMS];
        int roomCount;
};
#endif
