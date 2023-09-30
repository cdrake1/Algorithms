//This file creates the sort classes
#include "Sorts.hpp"

#include <vector>
#include <iostream>
#include <string>

vector<string> Sorts:: knuthShuffle(vector<string>& magicItems){ //randomly shuffles all elements in magic items

    srand (time(NULL)); //initialize seed value so we get different random nums

    for(int i = 0; i < magicItems.size(); i++){ //iterate through each line in magic items
        int random = rand() % magicItems.size(); //generate random number between 1 and vector length
        string temp = magicItems[i]; //swap
        magicItems[i] = magicItems[random];
        magicItems[random] = temp;
    }
    return magicItems;
}

void Sorts:: selectionSort(vector<string>& magicItems){ //selection sort to sort magic items
    int sComparisons = 0; //comparisons counter for selection sort
    for(int i = 0; i < magicItems.size(); i++){ //iterate through vector
        int smallestPos = i; //smallest index
        for(int j = i + 1; j < magicItems.size(); j++){ //increment and compare elements with smallest
            sComparisons++; //increment comparisons
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
    cout<<"Selection sort comparisons: " << sComparisons << "\n";
}

void Sorts:: insertionSort(vector<string>& magicItems){ //insertion sort to sort magic items
    int iComparisons = 0;
    for(int i = 1; i < magicItems.size(); i++){ //iterate through vector. first element sorted
        string current = magicItems[i];
        int j = i - 1; //check with previous element
        while(j >= 0 && current.compare(magicItems[j]) < 0){
            iComparisons++;
            magicItems[j + 1] = magicItems[j];
            j--;
        }
        magicItems[j + 1] = current;
    }
    cout<<"Insertion sort comparisons: " << iComparisons << "\n";
}

void Sorts:: mergeSort(vector<string>& magicItems, int start, int end, int& comparisons){ //merge sort to sort magic items
    if(start >= end){
        return;
    }
    int middle = (start + end) / 2; //find middle point
    mergeSort(magicItems, start, middle, comparisons); //sort left
    mergeSort(magicItems, middle + 1, end, comparisons); //sort right
    merge(magicItems, start, middle, end, comparisons); //merge sorted arrays
}

void Sorts:: merge(vector<string>& magicItems, int start, int middle, int end, int& comparisons){ //merge sorted arrays together
    //declare left and right pointer. Also create temp sub array of proper length
    int left = start, right = middle + 1;
    vector<string> subVec(end - start + 1);

    //iterate through sub array
    for(int i = 0; i < end - start + 1; i++){
        comparisons++; //count comparisons
        if(right > end){
            //add element from left side
            subVec.at(i) = magicItems.at(left);
            left++;
        }
        else if (left > middle)
        {
            //add element from right side
            subVec.at(i) = magicItems.at(right);
            right++;
        }
        else if (magicItems.at(left).compare(magicItems.at(right)) < 0)
        {
            //add element from left side
            subVec.at(i) = magicItems.at(left);
            left++;
        }
        else{
            //add element from right side
            subVec.at(i) = magicItems.at(right);
            right++;
        }
    }
    //move subvector elements to main vector
    for(int j = 0; j < end - start + 1; j++){
        magicItems.at(start + j) = subVec.at(j);
    }
}


void Sorts:: quickSort(vector<string>& magicItems, int start, int end){
    if(start >= end){
        return;
    }
    int pivot = magicItems.at(); //choose pivot

    int r = partition(magicItems, start, end, pivot);
    quickSort(magicItems, start, r - 1);
    quickSort(magicItems, r + 1, end);
}

int Sorts:: partition(vector<string>& magicItems, int start, int end, int pivot){
    string temp = magicItems.at(pivot);
    magicItems.at(pivot) = magicItems.at(end);
    magicItems.at(end) = temp;
    temp = nullptr;

    int l = 0;
    for(int i = 1; i < end - 1; i++){
        if(magicItems.at(i).compare(magicItems.at(end)) < 0){
            l += 1;
            temp = magicItems.at(l);
            magicItems.at(l) = magicItems.at(i);
            magicItems.at(i) = temp;
            temp = nullptr;
        }
    }
    temp = magicItems.at(end);
    magicItems.at(end) = magicItems.at(l + 1);
    magicItems.at(l + 1) = temp;
    temp = nullptr;

    return l + 1; //returns new index of pivot

}
