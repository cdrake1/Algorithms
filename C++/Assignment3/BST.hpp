//header file for BST
#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

#include <string>

using namespace std;

class BST{
    public:
        BST(); // binary search tree constructor
        Node* root; //initialize root node
        void BSTInsert(string value); //insert a node into the BST
        void TreeSearch(); //search the BST for a particular value
};

#endif