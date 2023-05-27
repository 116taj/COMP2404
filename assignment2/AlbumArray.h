#ifndef ALBUM_ARRAY_H
#define ALBUM_ARRAY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "defs.h"
using namespace std;

class AlbumArray {
    public:
        AlbumArray();
        ~AlbumArray();
        bool isFull() const;
        bool add(Album* toAdd);
        Album* get(const string& title) const;
        Album* get(int i) const;
        Album* remove(const string& t);
        Album* remove(int i);
        int size() const;
    private:
        Album** albums;
        int albumCount;
};
#endif