//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std;

class Node{
    public:
        Node(string val); //Node constructor
        string val; //data in node
        Node* left; //pointer to next node
        Node* right; //pointer to next node
        Node* parent; //pointer to next node
};

#endif