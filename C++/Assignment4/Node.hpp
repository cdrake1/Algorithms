//header file for Node
#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <stdexcept>

using namespace std;

class Node{
    public:
        Node(string val); //node constructor
        string val; //data in node
        Node* next; //pointer to next node
};

class Stack{
    public:
        Stack(); //stack constructor
        void push(string val); //adds new element to the top
        string pop(); //removes element from the top
        bool isEmpty(); //checks if empty
    private:
        Node* top; //points to top
};

#endif