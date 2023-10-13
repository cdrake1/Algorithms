//This file creates the search classes
#include "Searching.hpp"

#include <vector>
#include <string>

//linear search
int Searching:: linearSearch(vector<string>& magicItems, vector<string>& randomItems){
    int lComparisons = 0;
    //iterate through both vectors
    for(int i = 0; i < randomItems.size(); i++){
        string current = randomItems[i];
        for(int j = 0 ; j < magicItems.size(); j++){
            //compare each element in magic items to current element in random items
            lComparisons++;
            if(current.compare(magicItems[j]) == 0){
                break;
            }
        }
    }
    return lComparisons;
}

//binary search
int Searching:: binarySearch(){
    return 0;
}