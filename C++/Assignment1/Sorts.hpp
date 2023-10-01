//header file for Shuffles
#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>
#include <string>

using namespace std;

class Sorts{
    public:
        //declarations of all sorts and shuffles
        void knuthShuffle(vector<string>& magicItems);
        void selectionSort(vector<string>& magicItems);
        void insertionSort(vector<string>& magicItems);
        void mergeSort(vector<string>& magicItems, int start, int end, int& comparisons);
        void merge(vector<string>& magicItems, int start, int middle, int end, int& comparisons);
        void quickSort(vector<string>& magicItems, int start, int end, int& comparisons);
        int partition(vector<string>& magicItems, int start, int end, string pivot, int& comparisons);
};

#endif