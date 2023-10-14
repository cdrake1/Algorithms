//This file creates the search classes for linear and binary search
#include "Searching.hpp"

#include <vector>
#include <string>

//linear search
float Searching:: linearSearch(vector<string>& magicItems, vector<string>& randomItems){
    //total comparisons
    int totlinComparisons = 0;

    //iterate through both vectors
    for(int i = 0; i < randomItems.size(); i++){
        //comparisons for each magic item
        int lComparisons = 0;
        string current = randomItems[i];
        for(int j = 0 ; j < magicItems.size(); j++){
            //compare each element in magic items to current element in random items
            lComparisons++;
            if(current.compare(magicItems[j]) == 0){
                //if found break loop
                break;
            }
        }
        //add to total
        totlinComparisons += lComparisons;
    }
    //find everage and round
    return (static_cast<float>(totlinComparisons) / static_cast<float>(randomItems.size()));
}

//binary search
float Searching:: binarySearch(vector<string>& magicItems, vector<string>& randomItems){
    //keep track of total comparisons
    int totbinComparisons = 0;
    
    //iterate through each element in random items
    for(int i = 0; i < randomItems.size(); i++){
        //comparisons for each magic item
        //current is the target
        //create start and end index variables
        int bComparisons = 0;
        string target = randomItems[i];
        int start = 0;
        int end = magicItems.size() - 1;

        while(start <= end){
            bComparisons++;
            //find middle index
            int middle = (start + end) / 2;

            //check if target is middle
            if(magicItems[middle] == target){
                break;
            }
            //if target is greater than middle, ignore left half
            if(magicItems[middle].compare(target) < 0){
                start = middle + 1;

            }
            //if target is less than middle, ignore right half
            else{
                end = middle - 1;
            }
        }
        //add to total
        totbinComparisons += bComparisons;
    }
    //find average and round
    return (static_cast<float>(totbinComparisons) / static_cast<float>(randomItems.size()));
}