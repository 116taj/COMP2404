#include "Room.h"

Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    reservationCount = 0;
}

Room::~Room(){
    for (int i = 0; i < reservationCount; i++){
        delete reservations[i];
    }
}

int Room::getRoomNumber(){
    return roomNumber;
}

bool Room::lessThan(Room& r){
    if (this->roomNumber < r.roomNumber)
        return true;
    return false;    
}
//check if room matches requirements
bool Room::isMatch(string bt, int cap, bool f){
    if (f){
        if (!this->hasFridge)
            return false;
    }
    if (this->bedType == bt && this->capacity >= cap)
        return true;
    return false;    
}

bool Room::addReservation(string cName, Date& d, int dur){
    //if too many reservations exist, return false
    if (reservationCount == MAX_RES)
        return false;    
    Reservation* r = new Reservation(cName,d,dur);    
    int index = 0;
    //search for index to place reservation
    for (int i = 0; i < reservationCount; i++){
        //if reservations overlap, do not add
        if (r->overlaps(*reservations[i])){
            delete r;
            return false;
        }
        if (reservations[i]->lessThan(d)){
            index = i;
        }
    }
    //shift array to open up spot
    for (int i = reservationCount; i > index; i--){
        reservations[i] = reservations[i-1];
    }    
    //place new reservation in that spot
    reservations[index] = r;
    reservationCount++;
    return true;
}

void Room::updateReservations(Date& cd){
    //create copy of array to place still valid reservations
    Reservation* reserveCopy[MAX_RES];
    int index = 0;
    for (int i = 0; i < reservationCount; i++){
        //if reservation is valid
        if (!reservations[i]->lessThan(cd)){
            //place it in new array
            reserveCopy[index] = reservations[i];
            index++;
        } else {
            //else delete it entirely
            delete reservations[i];
        }
    }
    reservationCount = index;
    //deep copy new array to member var
    for (int i = 0; i < reservationCount; i++){
        reservations[i] = reserveCopy[i];
    }
}

void Room::print(){
    if (hasFridge)
        cout<<"Room number "<<roomNumber<<" contains bed type "<<bedType<< ", a fridge, and has a capacity of "<<capacity<<"."<<endl;
    else
        cout<<"Room number "<<roomNumber<<" contains bed type "<<bedType<< " and has a capacity of "<<capacity<<"."<<endl;
}

void Room::printReservations(){
    print();
    cout<<"This room has "<<reservationCount<<" reservations: "<<endl;
    for (int i = 0; i < reservationCount; i++){
        reservations[i]->print();
    }
}