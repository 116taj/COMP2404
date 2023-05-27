#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "PhotoGram.h"
#include "defs.h"
using namespace std;

class Client {
    public:
        Client();
        ~Client();
        bool downloadAlbum(PhotoGram* pg, const string& at);
        bool displayOnlinePhoto(PhotoGram* pg, const string& at, const string& pt) const;
        bool displayLocalPhoto(const string& at, const string& pt) const;
        void printLocalAlbums() const;
        void displayLocalAlbums() const;
    private:
        AlbumArray* albums;
};
#endif