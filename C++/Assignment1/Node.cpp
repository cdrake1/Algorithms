//This file creates the linkedlist/node class

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
    Node* top;

    public:
        void push(char val){
            Node* newNode = new Node(val);

            if (isEmpty()) //check if stack empty
            {
                top = newNode;
            }
            else{ //if not empty
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
    Node* front;
    Node* rear;

    public:

        void enqueue(char val){
            Node* newNode2 = new Node(val);
            if(isEmpty()){
                front = newNode2;
                rear = newNode2;
            }
            else{
                rear->next = newNode2;
                rear = newNode2;
            }
        }

        void dequeue(){
            if(isEmpty){
                throw invalid_argument("Queue is empty");
            }
            else{
                front = front->next;
            }
        }

        bool isEmpty(){
            if(front == nullptr){
                return true;
            }
            else{
                return false;
            }
        }

};