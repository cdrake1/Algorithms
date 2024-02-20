//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std;

class Node{
    public:
        Node(string val); //Node constructor
        string val; //data in node
        Node* left; //pointer to left node
        Node* right; //pointer to right node
        Node* parent; //pointer to parent node
};

#endif