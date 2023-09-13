//header file for Node
#ifndef READFILE_H
#define READFILE_H

#include <stdexcept>

using namespace std;

class Node{
    public:
        Node();
};

class Stack{
    public:
        void push();
        void pop();
        bool isEmpty();
};

class Queue{
    public:
        void enqueue();
        void dequeue();
        bool isEmpty();
};

#endif