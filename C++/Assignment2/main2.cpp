//main file to run assignment 1 folder
//rebuild progam2 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"
#include "MergeSort.hpp"
#include "Searching.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    //create readfile instance and read text file into magic items
    readFile reader;
    vector<string> magicItems = reader.readInto();

    //create instance of merge sort and sort magic items
    MergeSort sort;
    sort.mergeSort(magicItems, 0, magicItems.size() - 1);

    //initialize seed value so we get different random nums each time
    srand (time(NULL));
    //add 42 random items into vector
    vector<string> randomItems;
    for(int i = 0; i < 42; i++){
        //generate random number between 1 and vector length
        int random = rand() % magicItems.size();
        randomItems.push_back(magicItems[random]);
    }

    Searching search;
    int linearComparisons = search.linearSearch(magicItems, randomItems);
    cout<< "Linear Search comparisons: " << linearComparisons << "\n";

}