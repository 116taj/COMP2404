
#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Reservation {
		
	public:
		//constructors
		Reservation(string, Date&, int);
		
		//sets duration of reservation
		void setDuration(int);
		//checks if reservations overlap
        bool overlaps(Reservation&);
		//checks if this reservation occurs before the other
		bool lessThan(Reservation&);
		//checks if this reservation occurs before the given date
		bool lessThan(Date&);

		void print();
	
	private:
		//variables
		int duration;
		Date checkIn;
		string customerName;
};
#endif
