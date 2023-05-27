#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include "AlbumArray.h"
#include "defs.h"
using namespace std;

class PhotoGram {
    public:
        PhotoGram();
        ~PhotoGram();
        bool addAlbum(const string& t, const string& d);
        bool removeAlbum(const string& t);
        bool addPhoto(const string& t, const Photo& p);
        bool removePhoto(const string& at, const string& pt);
        Album* downloadAlbum(const string& t) const;
        Photo* downloadPhoto(const string& at, const string& pt) const;
        void printAlbums() const;
        void displayAlbums() const;
    private:
        AlbumArray* albums;
};
#endif