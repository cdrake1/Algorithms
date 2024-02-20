//header file for Queue Node
#ifndef QNODE_HPP
#define QNODE_HPP

#include "Vertex.hpp"

#include <stdexcept>

using namespace std;

class QNode{
    public:
        QNode(Vertex* val); //Node constructor
        Vertex* val; //data in node
        QNode* next; //pointer to next node
};

class Queue{
    public:
        Queue(); //Queue constructor
        void enqueue(Vertex* val); //enqueues new element
        Vertex* dequeue(); //removes front node
        bool isEmpty(); //checks if queue is empty
    private:
        QNode* head; //points to front
        QNode* tail; //points to back
};
#endif