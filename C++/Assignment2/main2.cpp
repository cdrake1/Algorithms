//main file to run assignment 2 folder
//rebuild progam2 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"
#include "MergeSort.hpp"
#include "Searching.hpp"
#include "Hashing.hpp"

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

    //create instance of search
    Searching search;
    //call linear and binary search, calculate, and output comparisons
    float linearComparisons = search.linearSearch(magicItems, randomItems);
    float binaryComparisons = search.binarySearch(magicItems, randomItems);
    //output comparisons
    cout<< "Average Linear Search comparisons: ";
    printf("%.2f", linearComparisons);
    cout<< "\n" << "Average Binary Search comparisons: ";
    printf("%.2f", binaryComparisons);
    cout<< "\n";

    //create instance of hash table
    HashTable hashtable;
    //total comparisons counter
    int totalComparisons = 0;
    //populate hash table with each element of magic items (666)
    for(int i = 0; i < magicItems.size(); i++){
        hashtable.put(magicItems[i]);
    }
    //get each random item (42) from the hash table
    for(int j = 0; j < randomItems.size(); j++){
        //output the random item and its comparison count
        string value = randomItems[j];
        int currentComparison = hashtable.get(randomItems[j]);
        totalComparisons += currentComparison;
        cout << j << ":" << value << ":" << currentComparison << "\n";
    }
    //output average hash comparisons
    float hashComparisons = (static_cast<float>(totalComparisons) / static_cast<float>(randomItems.size()));
    cout << "Average hash table get comparisons: ";
    printf("%.2f", hashComparisons);
    cout<< "\n";
}