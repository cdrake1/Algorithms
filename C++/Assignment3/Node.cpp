//This file creates the node class
//For use with graphs and trees
#include "Node.hpp"

#include <string>

Node::Node(string val){ //Node class constructor
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}