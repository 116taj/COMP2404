#include "PhotoArray.h"

PhotoArray::PhotoArray(){
    photos = new Photo*[MAX_ARRAY];
    photoCount = 0;
}

PhotoArray::~PhotoArray(){
    delete[] photos;
}

bool PhotoArray::isFull() const{
    if (photoCount == MAX_ARRAY)
        return true;
    return false;     
}

bool PhotoArray::addPhoto(Photo* p){
    if (isFull())
        return false;  
    photos[photoCount] = p;
    photoCount++;
    return true;
}

bool PhotoArray::addPhoto(int index, Photo* p){
    if (isFull() || index < 0 || index > photoCount)
        return false;
    //shift array to make room for new photo    
    for (int i = photoCount; i > index; i--){
        photos[i] = photos[i-1];
    }
    photos[index] = p;
    photoCount++;
    return true;    
}

Photo* PhotoArray::getPhoto(const string& title) const{
    for (int i = 0; i < photoCount; i++){
        if(photos[i]->getTitle() == title){
            return photos[i];
        }
    }
    return NULL;
}

Photo* PhotoArray::getPhoto(const int index) const{
    if (index < 0 || index >= photoCount)
        return NULL;
    return photos[index];    
}

Photo* PhotoArray::removePhoto(const string& title){
    int index;
    Photo* removed;
    for (int i = 0; i < photoCount; i++){
        if(photos[i]->getTitle() == title){
            index = i;
            removed = photos[i];
            break;
        }
    }

    for (int i = index; i+1 < photoCount; i++){
        photos[i] = photos[i+1];
    }
    photoCount--;
    return removed;
}

Photo* PhotoArray::removePhoto(const int index){
    if (index < 0 || index >= photoCount)
        return NULL;
    Photo* removed = photos[index];   
    for (int i = index; i+1 < photoCount; i++){
        photos[i] = photos[i+1];
    }
    photoCount--;
    return removed;
}

int PhotoArray::size() const{
    return photoCount;
}