//header file for Node
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
    public:
        Node(char val);
        char val;
        Node* next;
};

class Stack{
    public:
        void push(char val);
        char pop();
        bool isEmpty();
    private:
        Node* top;
};

class Queue{
    public:
        void enqueue(char val);
        char dequeue();
        bool isEmpty();
    private:
        Node* front;
        Node* rear;
};

#endif