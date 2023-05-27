#include "Pierres.h"

Pierres::Pierres(){
    drivers = DriverList();
    franchises = FranchiseList();
}

Pierres::~Pierres(){

}
void Pierres::addDriver(const string& n, const Location& l){
    drivers.add(new Driver(n,l));
}

void Pierres::addFranchise(const string& n, const Location& l){
    franchises.add(new Franchise(n,l));
}

//create order and add to closest franchose
void Pierres::takeOrder(const string& custN, int mI, const Location& l){
    Order* newOrder = new Order(custN,mI,l);
    Franchise* addTo = getClosestFranchise(l);
    addTo->addOrder(newOrder);
}

//find franchise by id, then if not null find closest driver
void Pierres::driverPickup(const string& fId, int numOrders){
    Franchise* pickup = franchises.get(fId);
    if (pickup == nullptr){
        cout<<"ERROR: FRANCHISE NOT FOUND! (id may be incorrect)"<<endl;
        return;
    }
    //if no drivers, null condition will occur
    Driver* closest = getClosestDriver(pickup->getLocation());
    if (closest == nullptr){
        cout<<"ERROR: DRIVER NOT FOUND! (id may be incorrect)"<<endl;
        return;
    }
    //update location and pickup orders
    closest->setLocation(pickup->getLocation());
    if (numOrders > pickup->getNumOrders())
        numOrders = pickup->getNumOrders();
    for (int i = 0; i < numOrders; i++){
        closest->addOrder(pickup->getNextOrder());
    }
}

//get driver by id and then deliver orders 
void Pierres::driverDeliver(const string& dId, int numOrders){
    Driver* delivery = drivers.get(dId);
    if (delivery == nullptr){
        cout<<"ERROR: DRIVER NOT FOUND! (id may be incorrect)"<<endl;
        return;
    }
    if (numOrders > delivery->getNumOrders())
        numOrders = delivery->getNumOrders();
    for (int i = 0; i < numOrders; i++){
        Order* o = delivery->getNextOrder();
        delivery->setLocation(o->getLocation());
        cout<<"Delivering: ";
        o->print();
        delete o;
    }
}

Franchise* Pierres::getClosestFranchise(const Location& l) const{
    return franchises.getClosestFranchise(l);
}

Driver* Pierres::getClosestDriver(const Location& l) const{
    return drivers.getClosestDriver(l);
}

void Pierres::printDrivers() const{
    drivers.print();
}

void Pierres::printFranchises() const{
    franchises.print();
}

