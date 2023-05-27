#ifndef PHOTO_ARRAY_H
#define PHOTO_ARRAY_H

#include <iostream>
#include <string>
#include "Photo.h"
#include "defs.h"
using namespace std;

class PhotoArray {
    public:
        PhotoArray();
        ~PhotoArray();
        bool isFull() const;
        bool addPhoto(Photo* toAdd);
        //setter
        bool addPhoto(int i,Photo* toAdd);
        Photo* getPhoto(const string& title) const;
        Photo* getPhoto(int i) const;
        Photo* removePhoto(const string& t);
        Photo* removePhoto(int i);
        int size() const;
    private:
        Photo** photos;
        int photoCount;
};
#endif