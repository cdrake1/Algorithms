//This file creates the linkedlist/node class
//Also creates stack and queue classes
#include "Node.hpp"

#include <stdexcept>
#include <string>

Node::Node(string val){ //Node class constructor
    this->val = val;
    this->next = nullptr;
}