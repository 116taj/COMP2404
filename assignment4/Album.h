#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Photo.h"
#include "defs.h"
using namespace std;

class Album {
    friend ostream& operator<<(ostream&, const Album&);	
    public:
        Album(const string& t, const string& d);
        bool equals(const string& t) const;
        void addPhoto(Photo*);
        Photo* getPhoto(int i) const;
        int size() const;
        void print(ostream&) const;
        void display(ostream&) const;
    private:
        Array<Photo*> photos;
        string title;
        string description;
};
#endif