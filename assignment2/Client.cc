#include "Client.h"

Client::Client(){
    albums = new AlbumArray();
}

Client::~Client(){
    for (int i = 0; i < albums->size(); i++){
        delete albums->get(i);
    }
    delete albums;
}
//create new album and add it
bool Client::downloadAlbum(PhotoGram* pg, const string& at){
    pg->downloadAlbum(at)->print();
    Album* a = new Album(*pg->downloadAlbum(at));
    bool result = albums->add(a);
    if (!result){
        //if error free the memory we just alloced
        delete a;
        cout<<"ERROR: ALBUM NOT ADDED."<<endl;
    }
    return result;
}

bool Client::displayOnlinePhoto(PhotoGram* pg, const string& at, const string& pt) const{
    Photo* toDisplay = pg->downloadPhoto(at,pt);
    if (toDisplay == NULL){
        cout<<"ERROR: PHOTO NOT FOUND."<<endl;
        return false;
    } 
    toDisplay->display();
    return true;
}

bool Client::displayLocalPhoto(const string& at, const string& pt) const{
    Photo* toDisplay = albums->get(at)->getPhoto(pt);
    if (toDisplay == NULL){
        cout<<"ERROR: PHOTO NOT FOUND."<<endl;
        return false;
    } 
    toDisplay->display();
    return true;
}

void Client::printLocalAlbums() const{
    for (int i = 0; i < albums->size(); i++) {
        albums->get(i)->print();
    }
}

void Client::displayLocalAlbums() const{
    for (int i = 0; i < albums->size(); i++) {
        albums->get(i)->display();
    }
}