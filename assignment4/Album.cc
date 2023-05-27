#include "Album.h"

Album::Album(const string& t, const string& d){
    title = t;
    description = d;
}

ostream& operator<<(ostream& ost, const Album& a){
    a.print(ost);
	return ost;
}

bool Album::equals(const string& t) const{
    if (t == title)
        return true;
    return false;    
}

void Album::addPhoto(Photo* p){
    photos+=p;
}

Photo* Album::getPhoto(int i) const{
    return photos[i];
}

int Album::size() const{
    return photos.size();
}
void Album::print(ostream& ost) const{
    ost<<title<<endl<<description<<endl<<"Photo Descriptions:"<<endl;
    for (int i = 0; i < photos.size(); i++){
        ost<<photos[i];
    }
}

void Album::display(ostream& ost) const{
    ost<<title<<endl<<description<<endl<<"Photo Display:"<<endl;
    for (int i = 0; i < photos.size(); i++){
        photos[i]->display(ost);
    }
}