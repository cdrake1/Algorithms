//This file creates the BST classes for insert and search
#include "BST.hpp";

#include <string>

BST:: BST(){ //BST constructor
    root = nullptr; //creates a BST and sets root to null
} 

void BST:: BSTInsert(Node* newNode){ //inserts a node into the BST
    if(root.val = nullptr){
        root = newNode;
    }
    Node* trailing = nullptr;
    Node* current = root;
    while(current != nullptr){
        trailing = current;
        if(newNode.val < current.val){
            current = current.left;
        }
        else{
            current = current.right;
        }
    }
    newNode.parent = trailing;
    if(trailing = nullptr){
        root = newNode;
    }
    else{
        if(newNode.val < trailing.val){
            trailing.left = newNode;
        }
        else{
            trailing.right = newNode;
        }
    }

}