#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Photo.h"
using namespace std;

class Criteria {
    friend ostream& operator<<(ostream&, const Criteria&);	
    public:
        virtual bool matches(const Photo&)const = 0;
        virtual void print(ostream&)const = 0;
};

class Cat_Criteria: virtual public Criteria {
    public:
        Cat_Criteria(const string&);
        bool matches(const Photo&) const;
        void print(ostream&) const;
    private:
        string category;    
};

class Date_Criteria: virtual public Criteria {
    public:
        Date_Criteria(const Date& s, const Date& e);
        bool matches(const Photo&) const;
        void print(ostream&) const;
    private:
        Date start;
        Date end; 
};

class CandD_Criteria: public Cat_Criteria, public Date_Criteria {
    public:
        CandD_Criteria(const Date& s, const Date& e, const string& c);
        bool matches(const Photo&) const;
        void print(ostream&) const;
    private:
        Date start;
        Date end; 
        string category;
};

#endif