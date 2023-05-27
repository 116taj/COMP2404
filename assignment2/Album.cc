#include "Album.h"

Album::Album(const string& t, const string& d){
    title = t;
    description = d;
    photos = new PhotoArray();
}

Album::Album(const Album& alb){
    photos = new PhotoArray();
    title = alb.title;
    description = alb.description;
    for (int i = 0; i < alb.photos->size(); i++){
        Photo* p =  alb.photos->getPhoto(i);
        Photo* p2 = new Photo(p->getTitle(),p->getDate(),p->getContent());
        photos->addPhoto(i,p2);
    }
}

Album::~Album(){
    for (int i = 0; i < photos->size(); i++){
        delete photos->getPhoto(i);
    }
    delete photos;
}

string Album::getTitle() const{
    return title;
}

bool Album::equals(const string& t) const{
    if (t == title)
        return true;
    return false;    
}

bool Album::lessThan(const Album& alb) const{
    if (title < alb.title)
        return true;
    return false;    
}

bool Album::addPhoto(Photo* p){
    return photos->addPhoto(p);
}

bool Album::addPhoto(int i, Photo* p){
    return photos->addPhoto(i,p);
}

Photo* Album::getPhoto(const string& t) const{
    return photos->getPhoto(t);
}

Photo* Album::getPhoto(int i) const{
    return photos->getPhoto(i);
}

Photo* Album::removePhoto(const string& t){
    return photos->removePhoto(t);
}

Photo* Album::removePhoto(int i){
    return photos->removePhoto(i);
}

int Album::size() const{
    return photos->size();
}
void Album::print() const{
    cout<<title<<endl<<description<<endl<<"Photo Descriptions:"<<endl;
    for (int i = 0; i < photos->size(); i++){
        photos->getPhoto(i)->print();
    }
}

void Album::display() const{
    cout<<title<<endl<<description<<endl<<"Photo Display:"<<endl;
    for (int i = 0; i < photos->size(); i++){
        photos->getPhoto(i)->display();
    }
}