#include "Photo.h"

Photo::Photo(){
    title = "Unnamed";
    date = Date();
    content = "None";
}
Photo::Photo(const string& title,const string& cat, const Date& d, const string& content){
    this->title = title;
    category = cat;
    this->date = d;
    this->content = content;
}

Photo::Photo(const Photo& toCopy){
    title = toCopy.title;
    date = toCopy.date;
    content = toCopy.content;
}

ostream& operator<<(ostream& ost, const Photo& p){
  	p.print(ost);
	return ost;
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

string Photo::getCategory() const{
    return category;
}
bool Photo::equals(const string& title) const{
    if (this->title == title)
        return true;
    return false;    
}

void Photo::print(ostream& ost) const{
    ost<<title<<" with category "<<category<< " was created on "<<date<<endl;
}
void Photo::display(ostream& ost) const{
    print(ost);
    ost<<content<<endl;
}