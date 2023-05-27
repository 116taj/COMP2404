#include "Order.h"
#include "Franchise.h"

Order::Order(const string& n, int mI, Location d){
    name = n;
    menuItem = mI;
    deliverTo = d;
}

Location Order::getLocation() const{
    return deliverTo;
}

void Order::print() const {
    cout<<"Order "<<name<<" has menu item ";
    cout<<Franchise::getMenu(menuItem)<<endl;
}