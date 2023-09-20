//This file creates the sort classes
#include "Sorts.hpp"

#include <vector>
#include <string>

using namespace std;

vector<string> Sorts:: knuthShuffle(vector<string> magicItems){

    for(int i = 0; i < magicItems.size(); i++){ //iterate through each line in magic items
        int random = rand() % magicItems.size() + 1; //generate random number between 1 and vector length
        string temp = magicItems[i]; //swap
        magicItems[i] = magicItems[random];
        magicItems[random] = temp;
    }
    return magicItems;
};