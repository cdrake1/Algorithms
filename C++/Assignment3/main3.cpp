//main file to run assignment 3 folder
//rebuild progam3 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"
#include"BST.hpp"

#include <iostream>
#include <string>
using namespace std;

int main(){
    //create readfile instance and read text file into magic items
    readFile reader;
    vector<string> magicItems = reader.readInto();

    //creates instance of BST and initializes root node
    BST binarySearchTree;

    for(int i = 0; i < magicItems.size(); i++){
        binarySearchTree.BSTInsert(magicItems[i]);
    }
}