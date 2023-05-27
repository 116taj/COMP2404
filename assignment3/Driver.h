#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"
using namespace std;

class Driver: public Entity {
    public:
        Driver(const string& n="Unnamed", const Location& l=Location());
        bool isFree() const;
        void print() const; 
    private:
        static int nextId;
        static const char code;
};

#endif