#ifndef DRIVER_LIST_H
#define DRIVER_LIST_H

#include <iostream>
#include <string>
#include "Driver.h"
using namespace std;

class DriverList {

    class Node{
        public:
            Driver* data;
            Node* next;
    };

    public:
        DriverList();
        ~DriverList();
        bool add(Driver* d);
        Driver* get(const string& id) const;
        Driver* getClosestDriver(const Location& l) const;
        Driver* remove(const string& id);
        void print() const; 
    private:
        Node* head;
        int count;
};

#endif