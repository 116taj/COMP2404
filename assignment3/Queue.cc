#include "Queue.h"

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

Queue::~Queue(){
   Node* curr = head;
   Node* prev;

   while(curr!= nullptr){
      prev = curr;
      curr = curr->next;
      delete prev->data;
      delete prev;
   }
}

bool Queue::empty() const {
    return count==0;
}

int Queue::size() const{
    return count;
}

Order* Queue::peekFirst() const{
    if (head == nullptr)
        return nullptr;
    return head->data;
}

Order* Queue::popFirst() {
    if (head == nullptr)
        return nullptr; 
    if (head == tail){
        tail = nullptr;
    }       
    Order* data = head->data;
    Node* next = head->next;
    delete head;
    head = next;
    count--;
    return data;    
}

void Queue::addLast(Order* o){
    Node* n = new Node();
    n->next = nullptr;
    n->data = o;
    if (head == nullptr)
        head = n;
    if (tail == nullptr)
        tail = n;
    else {
        tail->next = n;
        tail = n;
    }
    count++;    
}

void Queue::print() const{
    cout<<"List of orders:"<<endl;
    Node* curr = head;
    
    while (curr != nullptr){
        curr->data->print();
        curr = curr->next;
    }
    cout<<"List complete"<<endl;
}