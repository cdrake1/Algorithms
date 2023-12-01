//This file creates the merge sort classes
#include "Sorts.hpp"

#include <vector>
#include <iostream>
#include <string>

//merge sort to sort spice vector
void Sorts:: mergeSort(vector<Spices*>& allSpices, int start, int end){
    if(start >= end){
        return;
    }
    //find middle point, sort left, sort right, and merge the sorted arrays
    int middle = (start + end) / 2;
    mergeSort(allSpices, start, middle);
    mergeSort(allSpices, middle + 1, end);
    merge(allSpices, start, middle, end);
}

//merge sorted arrays together
void Sorts:: merge(vector<Spices*>& allSpices, int start, int middle, int end){
    //declare left and right pointers, subArray
    int left = start;
    int right = middle + 1;
    vector<Spices*> subVec(end - start + 1);

    //iterate through sub array
    for(int i = 0; i < end - start + 1; i++){
        if(right > end){
            //add element from left side
            subVec[i] = allSpices[left];
            left++;
        }
        else if (left > middle)
        {
            //add element from right side
            subVec[i] = allSpices[right];
            right++;
        }
        else if (allSpices[left]->unitPrice >= allSpices[right]->unitPrice)
        {
            //add element from left side
            subVec[i] = allSpices[left];
            left++;
        }
        else{
            //add element from right side
            subVec[i] = allSpices[right];
            right++;
        }
    }
    //move subvector elements to main vector
    for(int j = 0; j < end - start + 1; j++){
        allSpices[start + j] = subVec[j];
    }
}