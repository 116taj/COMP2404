#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Photo {
    public:
        Photo();
        Photo(const string& title, const Date& date, const string& content);
        Photo(const Photo& copy);
        string getTitle() const;
        string getContent() const;
        Date getDate() const;
        bool equals(const string& title) const;
        void print() const;
        void display() const;
    private:
        string title;
        string content;
        Date date;

};

#endif