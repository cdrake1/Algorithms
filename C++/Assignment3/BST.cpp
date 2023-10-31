//This file creates the BST classes for insert and search
#include "BST.hpp"

#include <string>
#include <iostream>

BST:: BST(){ //BST constructor
    //creates a BST and sets root to null
    root = nullptr;
} 

void BST:: BSTInsert(string value){ //inserts a node into the BST
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
        }
        else{
            //check if the new value is >= the current value
            current = current->right; //R
        }
    }
    //set parent node
    newNode->parent = trailing;
    if(trailing == nullptr){
        //if there is no parent then the new node becomes the root node
        root = newNode;
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
}