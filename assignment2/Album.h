#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "PhotoArray.h"
#include "defs.h"
using namespace std;

class Album {
    public:
        Album(const string& t, const string& d);
        Album(const Album& a);
        ~Album();
        string getTitle() const;
        bool equals(const string& t) const;
        bool lessThan(const Album& alb) const;
        bool addPhoto(Photo*);
        bool addPhoto(int, Photo*);
        Photo* getPhoto(const string& title) const;
        Photo* getPhoto(int i) const;
        Photo* removePhoto(const string& t);
        Photo* removePhoto(int i);
        int size() const;
        void print() const;
        void display() const;
    private:
        PhotoArray* photos;
        string title;
        string description;
};
#endif