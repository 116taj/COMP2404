#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "Order.h"

using namespace std;

class Queue{

    class Node{
        public:
            Order* data;
            Node* next;
    };

    public:
        Queue();
        ~Queue();
        bool empty() const;
        int size() const;
        Order* peekFirst() const;
        Order* popFirst();
        void addLast(Order* o);
        void print() const;
    private:
        Node* head;
        Node* tail;
        int count;
};


#endif

