//This file creates the linkedlist/node class
//Also creates stack and queue classes
#include "Node.h"

#include <stdexcept>

using namespace std;

Node::Node(char val){ //Node class constructor
    this->val = val;
    this->next = nullptr;
};

void Stack::push(char val){ //push node onto stack
    Node* newNode = new Node(val);
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
};

void Stack::pop(){ //pop top node off stack
    if (isEmpty()){
        throw invalid_argument("Stack is empty");
    }
    else{
        top = top->next;
    }
};

bool Stack::isEmpty(){ //check if stack is empty
    return top == nullptr;
};

void Queue::enqueue(char val){ //add node to back of line
    Node* newNode2 = new Node(val);
    if(isEmpty()){ //if empty make node front and rear
        front = newNode2;
        rear = newNode2;
    }
    else{ //if not make it rear
        rear->next = newNode2;
        rear = newNode2;
    }
};

void Queue::dequeue(){ //remove node from front of line
    if(isEmpty()){
        throw invalid_argument("Queue is empty");
    }
    else{
        front = front->next; //change front
    }
};

bool Queue::isEmpty(){ //check if queue is empty
    return front == nullptr;
};