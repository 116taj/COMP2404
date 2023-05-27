#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

class Entity {
    public:
        Entity(char idC, int idN, const string& n, const Location& l);
        void setLocation(const Location& l);
        int getNumOrders() const;
        Order* getNextOrder();
        Location getLocation() const;
        void addOrder(Order* order);
        void print() const;
        bool equals(const string& id) const;
    protected:
        string id;
        string name;
        Location loc;
        Queue orders;           
};

#endif