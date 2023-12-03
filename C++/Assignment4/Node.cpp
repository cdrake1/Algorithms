//This file creates the linkedlist/node class
//Also creates stack and queue classes
#include "Node.hpp"

Node::Node(string val){ //node class constructor
    this->val = val;
    this->next = nullptr;
}

Stack::Stack() { //stack class constructor
    top = nullptr;
}

void Stack::push(string val) { //push node onto stack
    Node* newNode = new Node(val);
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
        newNode = nullptr;
        delete newNode;
    }
}

string Stack::pop(){ //pop top node off stack
    if (isEmpty()){
        throw invalid_argument("The stack is empty");
    }
    else{
        Node* temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp->val;
        temp = nullptr;
        delete temp;
    }
}

bool Stack::isEmpty(){ //check if stack is empty
    return top == nullptr;
}
