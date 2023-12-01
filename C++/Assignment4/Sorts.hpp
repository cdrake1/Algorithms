//header file for merge sort
#ifndef SORTS_HPP
#define SORTS_HPP

#include "Spices.hpp"

#include <vector>
#include <string>

using namespace std;

class Sorts{
    public:
        //declarations of merge sort
        void mergeSort(vector<Spices*>& allSpices, int start, int end);
        void merge(vector<Spices*>& allSpices, int start, int middle, int end);
};

#endif