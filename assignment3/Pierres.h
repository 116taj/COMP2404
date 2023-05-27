#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include "DriverList.h"
#include "FranchiseList.h"
using namespace std;

class Pierres {
    public:
        Pierres();
        ~Pierres();
        void addDriver(const string& n, const Location& l);
        void addFranchise(const string& n, const Location& l);
        void takeOrder(const string& custN, int mI, const Location& l);
        void driverPickup(const string& fId, int numOrders);
        void driverDeliver(const string& dId, int numOrders);
        void printFranchises() const;
        void printDrivers() const;
    private:
        DriverList drivers;
        FranchiseList franchises;
        Franchise* getClosestFranchise(const Location& l) const;
        Driver* getClosestDriver(const Location& l) const;
};

#endif