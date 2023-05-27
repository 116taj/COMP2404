#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include <iostream>
#include <string>
#include "Photo.h"
#include "Array.h"
#include "MediaFactory.h"
#include "View.h"
#include "defs.h"
using namespace std;

class PhotoGram {
    public:
        PhotoGram();
        ~PhotoGram();
        void addAlbum(const string& t, const string& d);
        void addToAlbum(int, Array<Photo*>);
        void deleteAlbum(int i);
        void uploadPhoto(const string& t);
        void getPhotos(const Criteria&, Array<Photo*>&);
        void displayAlbum(int, View&) const;
        void displayPhoto(int, View&) const;
        int printAlbums(View&) const;
        int printPhotos(View&) const;
    private:
        Array<Album*> albums;
        Array<Photo*> masterList;
        MediaFactory factory;
};
#endif