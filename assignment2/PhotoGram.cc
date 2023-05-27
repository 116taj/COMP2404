#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    albums = new AlbumArray();
}

PhotoGram::~PhotoGram(){
    for (int i = 0; i < albums->size(); i++){
        delete albums->get(i);
    }
    delete albums;
}

bool PhotoGram::addAlbum(const string& t, const string& d){
    Album* a = new Album(t,d);
    bool result = albums->add(a);
    if (!result){
        cout<<"ERROR: ALBUM NOT ADDED."<<endl;
    }
    return result;
}

bool PhotoGram::removeAlbum(const string& t){
    Album* a = albums->remove(t);
    if (a == NULL){
        cout<<"ERROR: ALBUM NOT REMOVED."<<endl;
        return false;
    }
    delete a;
    return true;
}

bool PhotoGram::addPhoto(const string& at, const Photo& p){
    Photo* toAdd = new Photo(p);
    bool result = albums->get(at)->addPhoto(toAdd);
    if (!result){
        delete toAdd;
        cout<<"ERROR: PHOTO NOT ADDED."<<endl;
    }
    return result;
}

bool PhotoGram::removePhoto(const string& at, const string& pt){
    Photo* p = albums->get(at)->removePhoto(pt);
    if (p == NULL){
        cout<<"ERROR: PHOTO NOT REMOVED."<<endl;
        return false;
    }
    delete p;
    return true;
}

Album* PhotoGram::downloadAlbum(const string& t) const{
    return albums->get(t);
}

Photo* PhotoGram::downloadPhoto(const string& at, const string& pt) const{
    return albums->get(at)->getPhoto(pt);
}

void PhotoGram::printAlbums() const{
    for (int i = 0; i < albums->size(); i++){
        albums->get(i)->print();
    }
}

void PhotoGram::displayAlbums() const{
    for (int i = 0; i < albums->size(); i++){
        albums->get(i)->display();
    }
}