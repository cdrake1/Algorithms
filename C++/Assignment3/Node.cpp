//This file creates the linkedlist/node class
//For use with hashing and chaining
#include "Node.hpp"

#include <string>

Node::Node(string val){ //Node class constructor
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}