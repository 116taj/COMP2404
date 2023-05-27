#include "Hotel.h"

Hotel::Hotel(){
    roomCount = 0;
}

Hotel::~Hotel(){
    for (int i = 0; i < roomCount; i++){
        delete rooms[i];
    }
}
//adds a room to the hotel
bool Hotel::addRoom(int roomNum, string bt, int cap, bool fr){
    Room* r = new Room(roomNum,bt,cap,fr);
    //if no more rooms can fit or room number already exists
    if (roomCount == MAX_ROOMS || this->getRoom(roomNum,&r)){
        delete r;
        return false;
    }
    int index = 0;
    //searching for index to place new room in
    for (int i = 0; i < roomCount; i++){
        if (rooms[i]->getRoomNumber() < roomNum){
            index = i+1;
            break;
        }
    }
    //shift array to allow the new element to fit
    for (int i = roomCount; i > index; i--){
        rooms[i] = rooms[i-1];
    }    
    rooms[index] = r;
    roomCount++;
    print();
    return true;
}

bool Hotel::deleteRoom(int roomNum){
    int index = -1;
    //find room in array
    for (int i = 0; i < roomCount; i++){
        if (roomNum == rooms[i]->getRoomNumber()){
            index = i;
        }
    }
    //if not found, return false
    if (index == -1)
        return false;
    //else it exists and delete it    
    delete rooms[index];
    roomCount--;
    //shift array to cover gap
    for (int i = index; i < roomCount; i++){
        rooms[i] = rooms[i+1];
    }    
    return true;
}

//get room and place it inside output param
bool Hotel::getRoom(int roomNum, Room** r){
    for (int i = 0; i < roomCount; i++){
        if (roomNum == rooms[i]->getRoomNumber()){
            (*r) = rooms[i];
            return true;
        }
    }
    return false;
}

//add a reservation
bool Hotel::addReservation(string cust, string bt, int cap, bool fr, Date& d, int dur){
    for (int i = 0; i < roomCount; i++){
        //if room matches client request
        if (rooms[i]->isMatch(bt,cap,fr)){
            //and not taken
            if(rooms[i]->addReservation(cust,d,dur))
                return true;
        }
    }
    return false;
}
//update reservations for each room
void Hotel::updateReservations(Date& cd){
    for (int i = 0; i < roomCount; i++){
        rooms[i]->updateReservations(cd);
    }

}

void Hotel::print(){
    cout<<"This hotel contains "<<roomCount<< " rooms."<<endl;
    for (int i = 0; i < roomCount; i++){
        rooms[i]->print();
    }
}

void Hotel::printReservations(){
    cout<<"This hotel contains "<<roomCount<< " rooms."<<endl;
    for (int i = 0; i < roomCount; i++){
        rooms[i]->printReservations();
    }
}
