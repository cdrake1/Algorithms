/*
main file to run assignment 4 folder
rebuild program4 and run it by running: make followed by the exe name in terminal. 
To rebuild and run the program run; make clean, make, followed by the exe name in terminal
*/

#include "readFile.hpp"

#include <iostream>

using namespace std;

int main(){
    //create readfile instance
    readFile reader;
    //read spice.txt, create and output all spices & knapsacks
    reader.readKnapSack();
    //read graphs2.txt, create and output all graphs
    reader.readGraph();
}