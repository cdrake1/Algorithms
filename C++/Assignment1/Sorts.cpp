//This file creates the sort classes
#include "Sorts.hpp"

#include <vector>
#include <iostream>
#include <string>

void Sorts:: knuthShuffle(vector<string>& magicItems){ //randomly shuffles all elements in magic items

    srand (time(NULL)); //initialize seed value so we get different random nums

    for(int i = 0; i < magicItems.size(); i++){ //iterate through each line in magic items
        int random = rand() % magicItems.size(); //generate random number between 1 and vector length
        string temp = magicItems[i]; //swap
        magicItems[i] = magicItems[random];
        magicItems[random] = temp;
    }
}

void Sorts:: selectionSort(vector<string>& magicItems){ //selection sort to sort magic items
    int sComparisons = 0; //comparisons counter for selection sort
    for(int i = 0; i < magicItems.size(); i++){ //iterate through vector
        int smallestPos = i; //smallest index
        for(int j = i + 1; j < magicItems.size(); j++){ //increment and compare elements with smallest
            sComparisons++;
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
            subVec[i] = magicItems[left];
            left++;
        }
        else if (left > middle)
        {
            //add element from right side
            subVec[i] = magicItems[right];
            right++;
        }
        else if (magicItems[left].compare(magicItems[right]) < 0)
        {
            //add element from left side
            subVec[i] = magicItems[left];
            left++;
        }
        else{
            //add element from right side
            subVec[i] = magicItems[right];
            right++;
        }
    }
    //move subvector elements to main vector
    for(int j = 0; j < end - start + 1; j++){
        magicItems[start + j] = subVec[j];
    }
}


void Sorts:: quickSort(vector<string>& magicItems, int start, int end, int& comparisons){ //quick sort algorithm
    if(start >= end){
        return;
    }
    int pivotIndex = (start + end) / 2; //choose pivot index/value
    string pivot = magicItems[pivotIndex];

    pivotIndex = partition(magicItems, start, end, pivot, comparisons); //partition based on pivot

    quickSort(magicItems, start, pivotIndex - 1, comparisons); //sort left and right elements
    quickSort(magicItems, pivotIndex + 1, end, comparisons);
}

int Sorts:: partition(vector<string>& magicItems, int start, int end, string pivot, int& comparisons){
    int l = start - 1; //less than pivot elements

    for(int i = start; i <= end - 1; i++){ //iterate from start to end
        comparisons++;
        if(magicItems[i].compare(pivot) < 0){ //check if less than pivot, swap, and increment
            l++;
            string temp = magicItems[l]; //swap
            magicItems[l] = magicItems[i];
            magicItems[i] = temp;
        }
    }
    string temp1 = magicItems[l + 1]; //swap
    magicItems[l + 1] = magicItems[end];
    magicItems[end] = temp1;

    return l+1; //return elements less than pivot

}
