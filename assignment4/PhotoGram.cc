#include "PhotoGram.h"

PhotoGram::PhotoGram(){

}

PhotoGram::~PhotoGram(){

}

void PhotoGram::addAlbum(const string& t, const string& d){
    Album* a = factory.createAlbum(t,d);
    albums+=a;
}

void PhotoGram::addToAlbum(int index, Array<Photo*> photoArr){
    for (int i = 0; i < albums.size(); i++){
        albums[index]->addPhoto(photoArr[i]);
    }
}

void PhotoGram::uploadPhoto(const string& t){
    Photo* p = factory.uploadPhoto(t);
    masterList+=p;
}
void PhotoGram::deleteAlbum(int i){
    if (i < 0 || i >= albums.size()){
        cout<<"error: index invalid"<<endl;
        return;
    }
    Album* toDelete = albums[i];
    albums-=albums[i];
    delete toDelete;
}

void PhotoGram::getPhotos(const Criteria& c, Array<Photo*>& ap) {
    for (int i = 0; i < masterList.size(); i++){
        if (c.matches(*masterList[i]))
            ap+=masterList[i];
    }
}

void PhotoGram::displayAlbum(int i, View& v) const{
    if (i < 0 || i >= albums.size()){
        cout<<"error: index invalid"<<endl;
        return;
    }
    v.displayAlbum(*albums[i]);
}


void PhotoGram::displayPhoto(int i, View& v) const{
    if (i < 0 || i >= masterList.size()){
        cout<<"error: index invalid"<<endl;
        return;
    }
    v.displayPhoto(*masterList[i]);
}

int PhotoGram::printAlbums(View& v) const{
    v.printAlbums(albums);
    return albums.size();
}

int PhotoGram::printPhotos(View& v) const{
    v.printPhotos(masterList);
    return masterList.size();
}