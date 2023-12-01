/*
main file to run assignment 4 folder
rebuild program4 and run it by running: make followed by the exe name in terminal. 
To rebuild and run the program run; make clean, make, followed by the exe name in terminal
*/

#include "readFile.hpp"
#include "Sorts.hpp"

#include <iostream>

using namespace std;

int main(){
    readFile reader;


    //spice & knapsack
    vector<Spices*> allSpices = reader.readKnapSack();

    Sorts sort;
    sort.mergeSort(allSpices, 0, allSpices.size() - 1);
}