//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

class Node{
    public:
        Node(char val); //Node constructor
        char val; //data in node
        Node* next; //pointer to next node
};

class Stack{
    public:
        Stack(); //Stack constructor
        void push(char val); //adds new element to the top
        char pop(); //removes element from the top
        bool isEmpty(); //checks if empty
    private:
        Node* top; // points to top
};

class Queue{
    public:
        Queue(); //Queue constructor
        void enqueue(char val); //enqueues new element
        char dequeue(); //removes front node
        bool isEmpty(); //checks if queue is empty
    private:
        Node* head; //points to front
        Node* tail; //points to back
};

#endif