//header file for Shuffles
#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <string>

using namespace std;

class Sorts{
    public:
        vector<string> knuthShuffle(vector<string>& magicItems);
        void selectionSort(vector<string>& magicItems);
        void insertionSort(vector<string>& magicItems);
        void mergeSort(vector<string>& magicItems, int start, int end);
        void merge(vector<string>& magicItems, int start, int middle, int end);
        void quickSort();
        void partition();
};

#endif