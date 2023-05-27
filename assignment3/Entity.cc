#include "Entity.h"

Entity::Entity(char idC, int idN, const string& n, const Location& l){
    id = idC+to_string(idN);
    name = n;
    loc = l;
    orders = Queue();
}

void Entity::setLocation(const Location& l){
    loc = l;
}

int Entity::getNumOrders() const{
    return orders.size();
}

Order* Entity::getNextOrder(){
    return orders.popFirst();
}

Location Entity::getLocation() const{
    return loc;
}
void Entity::addOrder(Order* order){
    orders.addLast(order);
}

void Entity::print() const{
    cout<<"Entity "<<name<<" with id "<<id<<" is at ";
    loc.print();
    cout<<" and has "<<getNumOrders()<< " orders."<<endl;
}

bool Entity::equals(const string& id) const{
    if (id == this->id)
        return true;
    return false;    
}