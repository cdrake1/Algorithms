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

    //iterate through BST
    while(current != nullptr){
        trailing = current;
        if(newNode->val < current->val){
            //check if the new value is < the current value
            current = current->left; //L
            path.append("L");
        }
        else{
            //check if the new value is >= the current value
            current = current->right; //R
            path.append("R");
        }
    }
    //set parent node
    newNode->parent = trailing;
    if(trailing == nullptr){
        //if there is no parent then the new node becomes the root node
        root = newNode;
        path.append("root node inserted");
    }
    else{
        //if there is a parent find out if new node goes left or right
        if(newNode->val < trailing->val){
            trailing->left = newNode;
        }
        else{
            trailing->right = newNode;
        }
    }
    cout<< path << "\n"; //output path
}

Node* BST:: TreeSearch(Node* node, string key){ //lookup values in the BST
    if(node == nullptr || node->val == key){
        return node; //return the retrieved value
    }
    else if(key < node->val){ // <
        return TreeSearch(node->left, key); //recursive call move left
    }
    else{ // >=
        return TreeSearch(node->right, key); //recursive call move right
    }
}