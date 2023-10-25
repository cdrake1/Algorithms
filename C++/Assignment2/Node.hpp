//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

using namespace std;

class Node{
    public:
        Node(string val); //Node constructor
        string val; //data in node
        Node* next; //pointer to next node
};

#endif