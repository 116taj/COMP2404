#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    albums = new Album*[MAX_ARRAY];
    albumCount = 0;
}

AlbumArray::~AlbumArray(){
    delete[] albums;
}

bool AlbumArray::isFull() const{
    if (albumCount == MAX_ARRAY)
        return true;
    return false;     
}
bool AlbumArray::add(Album* a){
    //adds album if not full
    if (isFull())
        return false;  
    albums[albumCount] = a;
    albumCount++;      
    //loop through from new element position to beginning, swapping elements if needed 
    for (int i = albumCount-1; i-1 >= 0; i--){
        if(!albums[i-1]->lessThan(*albums[i])){
            Album* temp = albums[i];
            albums[i] = albums[i-1];
            albums[i-1] = temp;
        }
    }   
    return true;
}
Album* AlbumArray::get(const string& title) const{
    //find title and return it
    for (int i = 0; i < albumCount; i++){
        if(albums[i]->getTitle() == title){
            return albums[i];
        }
    }
    return NULL;
}

Album* AlbumArray::get(int index) const{
    if (index < 0 || index >= albumCount)
        return NULL;
    return albums[index];    
}

Album* AlbumArray::remove(const string& title){
    int index;
    Album* removed;
    for (int i = 0; i < albumCount; i++){
        if(albums[i]->getTitle() == title){
            index = i;
            removed = albums[i];
            break;
        }
    }
    //shift array to fill the gap
    for (int i = index; i+1 < albumCount; i++){
        albums[i] = albums[i+1];
    }
    albumCount--;
    return removed;
}

Album* AlbumArray::remove(int index) {
    if (index < 0 || index >= albumCount)
        return NULL;
    Album* removed = albums[index];   
    for (int i = index; i+1 < albumCount; i++){
        albums[i] = albums[i+1];
    }
    albumCount--;
    return removed;
}

int AlbumArray::size() const{
    return albumCount;
}