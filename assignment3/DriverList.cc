#include "DriverList.h"

DriverList::DriverList(){
    head = nullptr;
    count = 0;
}


DriverList::~DriverList(){
   Node* curr = head;
   Node* prev;
   while(curr!= nullptr){
      prev = curr;
      curr = curr->next;
      delete prev->data;
      delete prev;
   }

}

//add to linked list
bool DriverList::add(Driver* d){
    count++;
    //if head uninit, init it
    if (head == nullptr){
        head = new Node;
        head->data = d;
        head->next = nullptr;  
        return true;
    }
    //else head exists and we need to loop to end
    Node* curr = head;
    while(curr->next!=nullptr){
        curr = curr->next;
    }
    //create node and add to end
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    curr->next = newNode;
    return true;
}

//remove node
Driver* DriverList::remove(const string& id){
    //if head is null then list is empty
    if (head == nullptr)
        return nullptr;
    //loop through list and find id    
    //when we find id break out
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr){
        if (curr->data->equals(id))
            break;
        prev = curr;
        curr = curr->next;
    }
    //handle not found 
    if (curr == nullptr)
        return nullptr;
    //handle head removal    
    if (prev == nullptr){
        head = head->next;
    } else {
        prev->next = curr->next;
    }
    //get the data and return it
    Driver* removed = curr->data;
    delete curr;
    count--;
    return removed;
}

Driver* DriverList::get(const string& id) const{
    //get driver by id if possible
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

Driver* DriverList::getClosestDriver(const Location& l) const{
    //min algorithm with linked list
    if (head == nullptr)
        return nullptr;
    Node* curr = head;
    int minDistance = -1;
    Driver* closest = nullptr;
    while (curr != nullptr){
        //additional condition of making sure driver is free 
        //requires minDistance to not be the head as the head of list may not be free
        int d = curr->data->getLocation().getDistance(l);
        if ((d < minDistance || minDistance == -1) && curr->data->isFree()){
            minDistance = d;
            closest = curr->data;
        }
        curr = curr->next;
    }
    return closest;
}

void DriverList::print() const{
    cout<<"There are "<<count<<" drivers.";
    cout<<"List of drivers:"<<endl;
    Node* curr = head;
    while(curr!=nullptr){
        curr->data->print();
        curr = curr->next;
    }
}



