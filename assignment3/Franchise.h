#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "defs.h"
using namespace std;

class Franchise: public Entity {
    public:
        Franchise(const string& n="Unnamed", const Location& l=Location());
        void print() const; 
        static void printMenu();
        static string getMenu(int i);

    private:
        static int nextId;
        static const char code;
        static const string menu[MENU_ITEMS];
};

#endif