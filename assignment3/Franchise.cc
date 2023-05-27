#include "Franchise.h"

int Franchise::nextId = 1;
const string Franchise::menu[] = {"1. Large Poutine", "2. Medium Poutine", "3. Small Poutine"};
const char Franchise::code = 'F';


Franchise::Franchise(const string& n, const Location& l): Entity(code,nextId++,n,l){}

void Franchise::print() const{
    cout<<"Franchise "<<name<<" with id "<<id<<" is at ";
    loc.print();
    cout<<" and has "<<getNumOrders()<< " orders."<<endl;
}

void Franchise::printMenu(){
    for (int i = 0; i < MENU_ITEMS; i++){
        cout<<menu[i]<<endl;
    }
}

string Franchise::getMenu(int i){
    if (i < 0  || i >= MENU_ITEMS)
        return "unknown menu item";
    return menu[i];
}