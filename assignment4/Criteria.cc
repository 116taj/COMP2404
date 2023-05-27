#include "Criteria.h"

ostream& operator<<(ostream& ost, const Criteria& c){
  	c.print(ost);
	return ost;
}

Cat_Criteria::Cat_Criteria(const string& cat){
    category = cat;
}

bool Cat_Criteria::matches(const Photo& p) const{
    return (p.getCategory() == category);
}

void Cat_Criteria::print(ostream& ost) const{
    ost<<"Search has category criteria "<<category<<endl;
}

Date_Criteria::Date_Criteria(const Date& s, const Date& e){
    start = s;
    end = e;
}

bool Date_Criteria::matches(const Photo& p) const{
    return (p.getDate() >= start && p.getDate() <= end);
}

void Date_Criteria::print(ostream& ost) const{
    ost<<"Search has date criteria "<<start<<" begin date, and " <<end<<" end date"<<endl;
}

CandD_Criteria::CandD_Criteria(const Date& s, const Date& e, const string& cat): Cat_Criteria(cat), Date_Criteria(s,e){
    start = s;
    end = e;
    category = cat;
}

bool CandD_Criteria::matches(const Photo& p) const{
    return (p.getDate() >= start && p.getDate() <= end) && (p.getCategory() == category);
}

void CandD_Criteria::print(ostream& ost) const{
    ost<<"Search has date criteria "<<start<<" begin date, and " <<end<<" end date."<<"\n"<<"Search has category criteria "<<category<<endl;
}