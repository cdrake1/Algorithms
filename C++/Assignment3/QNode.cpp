//This file creates the queue node class

#include "QNode.hpp"

QNode::QNode(Vertex* val){ //Node class constructor
    this->val = val;
    this->next = nullptr;
}

Queue::Queue() { //Queue class constructor
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue(Vertex* val){ //add node to back of line
    QNode* newNode2 = new QNode(val);
    if(isEmpty()){ //if empty make node head and tail
        head = newNode2;
        tail = newNode2;
    }
    else{ //if not make it rear
        tail->next = newNode2;
        tail = newNode2;
    }
}

Vertex* Queue::dequeue(){ //remove node from front of line
    if(isEmpty()){
        throw invalid_argument("The queue is empty");
    }
    else{
        QNode* temp = head;
        head = head->next; //change front
        if(head == nullptr){
            tail = nullptr;
        }
        return temp->val;
        temp = nullptr;
        delete temp;
    }
}

bool Queue::isEmpty(){ //check if queue is empty
    return head == nullptr;
}