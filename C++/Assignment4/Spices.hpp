//header file for knapsack and spices
#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Spices{
    public:
        Spices(string name, double price, int qty); //spice constructor
        //name, price, and qty of the spices
        string spiceName; 
        double unitPrice;
        int spiceQty;
        double totalPrice;
        bool processed;
};

class Knapsack{
    public:
        Knapsack(double capacity);
        void addItem(Spices* spice);
        void fractionalKnapsack(vector<Spices*> allSpices);
        void clearKnapsack();
        double knapCapacity;
        vector<Spices*> items;
};

class Sorts{
    public:
        //declarations of merge sort
        void mergeSort(vector<Spices*>& allSpices, int start, int end);
        void merge(vector<Spices*>& allSpices, int start, int middle, int end);
};

#endif