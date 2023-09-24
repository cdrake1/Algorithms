//This file creates the sort classes
#include "Sorts.hpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> Sorts:: knuthShuffle(vector<string> magicItems){

    srand (time(NULL)); //initialize seed value so we get different random nums

    for(int i = 0; i < magicItems.size(); i++){ //iterate through each line in magic items
        int random = rand() % magicItems.size(); //generate random number between 1 and vector length
        string temp = magicItems[i]; //swap
        magicItems[i] = magicItems[random];
        magicItems[random] = temp;
    }
    return magicItems;
};

void Sorts:: selectionSort(vector<string> magicItems){
    int Scomparisons = 0; //comparisons counter for selection sort
    for(int i = 0; i < magicItems.size(); i++){ //iterate through vector
        int smallestPos = i; //smallest index
        for(int j = i + 1; j < magicItems.size(); j++){ //increment and compare elements with smallest
            if(magicItems[smallestPos].compare(magicItems[j]) > 0){
                //if smaller change smallest
                smallestPos = j;
            }
            Scomparisons++; //increment comparisons
        }
        //swap using temp variable
        string temp = magicItems[i];
        magicItems[i] = magicItems[smallestPos];
        magicItems[smallestPos] = temp;
    }
    cout<<"Selection sort comparisons: " << Scomparisons << "\n";
};

void Sorts:: insertionSort(vector<string> magicItems){
    int Icomparisons = 0;
    for(int i = 1; i < magicItems.size(); i++){ //iterate through vector. first element sorted
        string current = magicItems[i];
        int j = i - 1; //check with previous element
        while(j >= 0 && current.compare(magicItems[j]) < 0){
            Icomparisons++;
            magicItems[j + 1] = magicItems[j];
            j--;
        }
        magicItems[j + 1] = current;
    }

    cout<<"Insertion sort comparisons: " << Icomparisons << "\n";

}