//This file creates the linkedlist/node class
//Also creates stack and queue classes
#include "Node.hpp"

#include <stdexcept>

using namespace std;

Node::Node(char val){ //Node class constructor
    this->val = val;
    this->next = nullptr;
};

Stack::Stack() { //Stack class constructor
    top = nullptr;
};

void Stack::push(char val) //push element onto stack
{ // push node onto stack
    Node* newNode = new Node(val);
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
};

char Stack::pop(){ //pop top node off stack
    if (isEmpty()){
        throw invalid_argument("The stack is empty");
    }
    else{
        Node* temp = top;
        top = top->next;
        return temp->val;
    }
};

bool Stack::isEmpty(){ //check if stack is empty
    return top == nullptr;
};

Queue::Queue() { //Queue class constructor
    front = nullptr;
    rear = nullptr;
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

char Queue::dequeue(){ //remove node from front of line
    if(isEmpty()){
        throw invalid_argument("The queue is empty");
    }
    else{
        Node* temp = front;
        front = front->next; //change front
        return temp->val;
    }
};

bool Queue::isEmpty(){ //check if queue is empty
    return front == nullptr;
};