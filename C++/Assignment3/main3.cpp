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
    vector<string> magicItems = reader.readMagicItems();
    vector<string> findMagicItems = reader.readFindMagicItems();

    //creates instance of BST and initializes root node
    BST binarySearchTree;

    //insert each element in magic items into the BST
    //cout << "The path taken to insert each node:" << "\n";
    for(int i = 0; i < magicItems.size(); i++){ 
        binarySearchTree.BSTInsert(magicItems[i]);
    }

    //outputs entire BST using an in-order traversal
    //cout << "\n" << "The output of each item in the binary search tree using an in-order traversal:" << "\n";
    //binarySearchTree.InOrder(binarySearchTree.root);

    //search the BST for each magic item within the find magic items vector
    for(int j = 0; j < findMagicItems.size(); j++){
        //create path and comparison count for each target
        string path = "";
        int comparisons = 0;
        //call the function and keep track of all comparisons
        binarySearchTree.TreeSearch(binarySearchTree.root, findMagicItems[j], path, comparisons);
    }
    //type cast and output the total binary search tree comparison average
    float totalBSTComp = (static_cast<float>(binarySearchTree.totalBSTSearch) / static_cast<float>(findMagicItems.size()));
    cout<< "The average comparison count of BST search: " << totalBSTComp;



    reader.readGraph();
}