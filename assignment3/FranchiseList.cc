#include "FranchiseList.h"

//very similar to driverlist, check there for comments
FranchiseList::FranchiseList(){
    head = nullptr;
    count = 0;
}


FranchiseList::~FranchiseList(){
   Node* curr = head;
   Node* prev;

   while(curr!= nullptr){
      prev = curr;
      curr = curr->next;
      delete prev->data;
      delete prev;
   }
}

bool FranchiseList::add(Franchise* d){
    count++;
    if (head == nullptr){
        head = new Node;
        head->data = d;
        head->next = nullptr;  
        return true;
    }
    Node* curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    curr->next = newNode;
    return true;
}

Franchise* FranchiseList::remove(const string& id){
    if (head == nullptr)
        return nullptr;
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr){
        if (curr->data->equals(id))
            break;
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
        return nullptr;
    if (prev == nullptr){
        head = head->next;
    } else {
        prev->next = curr->next;
    }
    Franchise* removed = curr->data;
    delete curr;
    count--;
    return removed;
}

Franchise* FranchiseList::get(const string& id) const{
    if (head == nullptr)
        return nullptr;
    Node* curr = head;
    while (curr != nullptr){
        if (curr->data->equals(id))
            return curr->data;
        curr = curr->next;
    }
    return nullptr;
}

Franchise* FranchiseList::getClosestFranchise(const Location& l) const{
    if (head == nullptr)
        return nullptr;
    Node* curr = head;
    int minDistance = head->data->getLocation().getDistance(l);
    Franchise* closest = head->data;
    while (curr != nullptr){
        int d = curr->data->getLocation().getDistance(l);
        if (d < minDistance){
            minDistance = d;
            closest = curr->data;
        }
        curr = curr->next;
    }
    return closest;
}

void FranchiseList::print() const{
    cout<<"There are "<<count<<" Franchises.";
    cout<<"List of Franchises:"<<endl;
    Node* curr = head;
    while(curr!=nullptr){
        curr->data->print();
        curr = curr->next;
    }
}



