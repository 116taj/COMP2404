#include "Photo.h"

Photo::Photo(){
    title = "Unnamed";
    date = Date();
    content = "None";
}
Photo::Photo(const string& title,const Date& d, const string& content){
    this->title = title;
    this->date = d;
    this->content = content;
}

Photo::Photo(const Photo& toCopy){
    title = toCopy.title;
    date = toCopy.date;
    content = toCopy.content;
}

string Photo::getTitle() const{
    return title;
}

string Photo::getContent() const{
    return content;
}

Date Photo::getDate() const{
    return date;
}

bool Photo::equals(const string& title) const{
    if (this->title == title)
        return true;
    return false;    
}

void Photo::print() const{
    cout<<title<<" was created on ";
    date.print();
    cout<<endl;
}
void Photo::display() const{
    print();
    cout<<content<<endl;
}