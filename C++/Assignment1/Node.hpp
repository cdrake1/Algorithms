//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

class Node{
    public:
        Node(char val);
        char val;
        Node* next;
};

class Stack{
    public:
        Stack();
        void push(char val);
        char pop();
        bool isEmpty();
    private:
        Node* top;
};

class Queue{
    public:
        Queue();
        void enqueue(char val);
        char dequeue();
        bool isEmpty();
    private:
        Node* front;
        Node* rear;
};

#endif