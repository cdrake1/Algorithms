//This file creates the sort classes
#include "Sorts.hpp"

#include <vector>
#include <iostream>
#include <string>

vector<string> Sorts:: knuthShuffle(vector<string> magicItems){

    srand (time(NULL)); //initialize seed value so we get different random nums

    for(int i = 0; i < magicItems.size(); i++){ //iterate through each line in magic items
        int random = rand() % magicItems.size(); //generate random number between 1 and vector length
        string temp = magicItems[i]; //swap
        magicItems[i] = magicItems[random];
        magicItems[random] = temp;
    }
    return magicItems;
}

void Sorts:: selectionSort(vector<string> magicItems){
    int Scomparisons = 0; //comparisons counter for selection sort
    for(int i = 0; i < magicItems.size(); i++){ //iterate through vector
        int smallestPos = i; //smallest index
        for(int j = i + 1; j < magicItems.size(); j++){ //increment and compare elements with smallest
            Scomparisons++; //increment comparisons
            if(magicItems[smallestPos].compare(magicItems[j]) > 0){
                //if smaller change smallest
                smallestPos = j;
            }
        }
        //swap using temp variable
        string temp = magicItems[i];
        magicItems[i] = magicItems[smallestPos];
        magicItems[smallestPos] = temp;
    }
    cout<<"Selection sort comparisons: " << Scomparisons << "\n";
}

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

void Sorts:: mergeSort(vector<string> magicItems, int start, int end){
    if(end > start){
        int middle = end / 2; //find middle point
        mergeSort(magicItems, start, middle); //sort left
        mergeSort(magicItems, middle + 1, end); //sort right
        merge(magicItems, start, middle, end); //merge sorted arrays
    }

}

void Sorts:: merge(vector<string> magicItems, int start, int middle, int end){
    int left = start, right = middle + 1;

    for(int i = 0; i < end; i++){
        if(right > end){

        }
        else if (left > middle)
        {
            /* code */
        }
        else if (magicItems.at(left) < magicItems.at(right))
        {
            /* code */
        }
        else{

        }
    }
    for(){

    }
}