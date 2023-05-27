#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Photo {
    friend ostream& operator<<(ostream&, const Photo&);	
    public:
        Photo();
        Photo(const string& title, const string& cat, const Date& date, const string& content);
        Photo(const Photo& copy);
        string getTitle() const;
        string getContent() const;
        string getCategory() const;
        Date getDate() const;
        bool equals(const string& title) const;
        void print(ostream&) const;
        void display(ostream&) const;
    private:
        string title;
        string category;
        string content;
        Date date;

};

#endif