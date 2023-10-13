//This file creates the sort classes
#include "MergeSort.hpp"

#include <vector>
#include <iostream>
#include <string>

void MergeSort:: mergeSort(vector<string>& magicItems, int start, int end){ //merge sort to sort magic items
    if(start >= end){
        return;
    }
    int middle = (start + end) / 2; //find middle point
    mergeSort(magicItems, start, middle); //sort left
    mergeSort(magicItems, middle + 1, end); //sort right
    merge(magicItems, start, middle, end); //merge sorted arrays
}

void MergeSort:: merge(vector<string>& magicItems, int start, int middle, int end){ //merge sorted arrays together
    //declare left and right pointer. Also create temp sub array of proper length
    int left = start, right = middle + 1;
    vector<string> subVec(end - start + 1);

    //iterate through sub array
    for(int i = 0; i < end - start + 1; i++){
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