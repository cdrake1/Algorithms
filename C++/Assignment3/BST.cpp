//This file creates the BST classes for insert and search
#include "BST.hpp"

#include <string>
#include <iostream>

BST:: BST(){ //BST constructor
    //creates a BST and sets root to null
    root = nullptr;
} 

void BST:: BSTInsert(string value){ //inserts a node into the BST
    //string to keep track of the path for each inserted node
    string path = "";
    //create new node
    Node* newNode = new Node(value);
    //create trailing and current pointers
    Node* trailing = nullptr;
    Node* current = root;

    //iterate through BST if current/root is filled
    while(current != nullptr){
        trailing = current;
        if(newNode->val.compare(current->val) < 0){
            //If the new value is less than the current go left (<)
            current = current->left; //L
            path.append("L");
        }
        else{
            //If the new value is greater than or equal to the current go right (>=)
            current = current->right; //R
            path.append("R");
        }
    }
    //set parent node to trailing
    newNode->parent = trailing;
    if(trailing == nullptr){
        //if there is no parent then the new node becomes the root node
        root = newNode;
        path.append("root node inserted");
    }
    else{
        //if there is a parent find out if new node goes left or right
        if(newNode->val.compare(trailing->val) < 0){
            //left (<)
            trailing->left = newNode;
        }
        else{
            //right (>=)
            trailing->right = newNode;
        }
    }
    cout<< path << "\n"; //output path
}

Node* BST:: TreeSearch(Node* node, string key){ //lookup values in the BST
    if(node == nullptr || node->val == key){
        //return the retrieved value
        return node;
    }
    else if(key < node->val){ // <
        //recursive call move left
        return TreeSearch(node->left, key);
    }
    else{ // >=
        //recursive call move right
        return TreeSearch(node->right, key);
    }
}

void BST:: InOrder(Node* node){ //output entire BST with an in-order traversal
    if(node == nullptr){
        return;
    }
    //recursively call with child node on the left
    InOrder(node->left);
    //output the value of each node
    cout << node->val << "\n";
    //recursively call with child node on the right
    InOrder(node->right);
}