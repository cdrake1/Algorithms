//header file for merge sort
#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <string>

using namespace std;

class MergeSort{
    public:
        //declarations of all sorts and shuffles
        void mergeSort(vector<string>& magicItems, int start, int end);
        void merge(vector<string>& magicItems, int start, int middle, int end);
};

#endif