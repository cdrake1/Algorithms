//main file to run assignment 3 folder
//rebuild progam3 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"
#include"BST.hpp"

#include <iostream>
#include <string>
using namespace std;

int main(){
    //create readfile instance and read magic items and magic items find into separate vectors
    readFile reader;
    vector<string> magicItems = reader.readInto();
    vector<string> findMagicItems = reader.readIntoTwo();

    //creates instance of BST and initializes root node
    BST binarySearchTree;

    //insert each element in magic items into the BST
    /*
    cout << "The path taken to insert each node:" << "\n";
    for(int i = 0; i < magicItems.size(); i++){ 
        binarySearchTree.BSTInsert(magicItems[i]);
    }
    */

    //outputs entire BST using an in-order traversal
    cout << "\n" << "The output of each item in the binary search tree using an in-order traversal:" << "\n";
    //binarySearchTree.InOrder(binarySearchTree.root);
}