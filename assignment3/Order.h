#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Location.h"
using namespace std;

class Order {
    public:
        Order(const string& n, int m, Location d);
        Location getLocation() const;
        void print() const;
    private:
        string name;
        int menuItem;
        Location deliverTo;  
};

#endif