//header file for Linear and Binary Search
#ifndef SEARCHING_HPP
#define SEARCHING_HPP

#include <vector>
#include <string>

using namespace std;

class Searching{
    public:
        //declaration of linear and binary search
        float linearSearch(vector<string>& magicItems, vector<string>& randomItems);
        float binarySearch(vector<string>& magicItems, vector<string>& randomItems);

};


#endif