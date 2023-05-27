#ifndef FRANCHISE_LIST_H
#define FRANCHISE_LIST_H

#include <iostream>
#include <string>
#include "Franchise.h"
using namespace std;

class FranchiseList {

    class Node{
        public:
            Franchise* data;
            Node* next;
    };

    public:
        FranchiseList();
        ~FranchiseList();
        bool add(Franchise* d);
        Franchise* get(const string& id) const;
        Franchise* getClosestFranchise(const Location& l) const;
        Franchise* remove(const string& id);
        void print() const; 
    private:
        Node* head;
        int count;
};

#endif