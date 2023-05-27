#include "Driver.h"

int Driver::nextId = 1;
const char Driver::code = 'D';

Driver::Driver(const string& n, const Location& l): Entity(code,nextId++,n,l){}

bool Driver::isFree() const{
    return orders.empty();
}

void Driver::print() const{
    cout<<"Driver "<<name<<" with id "<<id<<" is at ";
    loc.print();
    cout<<" and has "<<getNumOrders()<< " orders."<<endl;
}
