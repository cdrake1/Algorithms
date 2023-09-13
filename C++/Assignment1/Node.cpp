//This file creates the linkedlist/node class
//Also creates stack and queue classes
#include "Node.h"

#include <stdexcept>


using namespace std;

class Node{
    public:
        Node* next; //pointer to next node
        char val; //data within node

        Node(char val){ //constructor for node class
            this->val = val;
            this->next = nullptr;
        }
};

class Stack{
    Node* top; //top of stack

    public:
        void push(char val){
            Node* newNode = new Node(val);

            if (isEmpty()) //check if stack empty
            {
                top = newNode;
            }
            else{ //if not empty make new node top
                newNode->next = top;
                top = newNode;
            }
        }
        void pop(){ //remove the top element of the stack
            if (isEmpty())
            {
               throw invalid_argument("Stack is empty");
            }
            else{
                top = top->next;
            }
        }
        bool isEmpty(){ //check if stack is empty
            if (top == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
};

class Queue{
    Node* front; //front and back of line/queue
    Node* rear;

    public:
        void enqueue(char val){ //enqueue new node
            Node* newNode2 = new Node(val);
            if(isEmpty()){ //if empty make node front and rear
                front = newNode2;
                rear = newNode2;
            }
            else{ //if not make it rear
                rear->next = newNode2;
                rear = newNode2;
            }
        }

        void dequeue(){ //dequeue first node
            if(isEmpty){
                throw invalid_argument("Queue is empty");
            }
            else{
                front = front->next; //change front
            }
        }

        bool isEmpty(){ //check if queue is empty
            if(front == nullptr){
                return true;
            }
            else{
                return false;
            }
        }
};