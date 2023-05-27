#include "Reservation.h"

Reservation::Reservation(string name, Date& d, int dur){
    setDuration(dur);
    this->customerName = name;
    this->checkIn = d;
}

void Reservation::setDuration(int duration){
    if (duration < 1){
        duration = 1;
    }
    this->duration = duration;
}

bool Reservation::overlaps(Reservation& r){
    if (r.checkIn.lessThan(this->checkIn)){
        Date end(r.checkIn);
        end.addDays(r.duration-1);
        if (end.lessThan(this->checkIn) || end.equals(this->checkIn)){
            return false;
        }
    } else if (this->checkIn.lessThan(r.checkIn)){
        Date end(this->checkIn);
        end.addDays(this->duration-1);
        if (end.lessThan(r.checkIn) || end.equals(r.checkIn)){
            return false;
        }
    } 
    return true;
}

bool Reservation::lessThan(Reservation& r){
    if (this->overlaps(r))
        return false;
    else if (this->checkIn.lessThan(r.checkIn))
        return true;
    return false;    
}

bool Reservation::lessThan(Date& d){
    if (this->checkIn.lessThan(d) || this->checkIn.equals(d))
        return true;
    return false;  
}

void Reservation::print(){
    cout<<"Reservation for "<<customerName<<" on ";
    checkIn.print();
    cout<<" for "<<duration<<" days."<<endl;
}
