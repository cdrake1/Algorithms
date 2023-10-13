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
                //if found break loop
                break;
            }
        }
    }
    return lComparisons;
}

//binary search
int Searching:: binarySearch(vector<string>& magicItems, vector<string>& randomItems){
    //keep track of comparisons
    int bComparisons = 0;
    
    //iterate through each element in random items
    for(int i = 0; i < randomItems.size(); i++){
        //current is the target
        //create start and end index vars
        string target = randomItems[i];
        int start = 0;
        int end = magicItems.size() - 1;

        while(start <= end){
            //find middle index
            int middle = (start + end) / 2;

        }
    }
}