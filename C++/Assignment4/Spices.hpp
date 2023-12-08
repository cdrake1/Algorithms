//header file for knapsack, spices, and sorts
#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Spices{ //spices class. creates and keeps track of spices
    public:
        Spices(string name, double price, int qty); //spice constructor
        //name, price, and qty of the spices
        string spiceName; 
        double unitPrice;
        int spiceQty;
        double totalPrice;
        bool processed;
};

class Knapsack{ //creates and keeps track of knapsacks
    public:
        Knapsack(double capacity); //knapsack constructor
        void addItem(Spices* spice); //adds an item to the knapsack
        void fractionalKnapsack(vector<Spices*> allSpices); //fractional knapsack algorithm
        void clearKnapsack(); //clears the knapsack and items vector
        double knapCapacity; //the knapsacks capacity
        vector<Spices*> items; //items stored in the knapsack
};

class Sorts{ //creates merge sort
    public:
        //declarations of merge sort
        void mergeSort(vector<Spices*>& allSpices, int start, int end);
        void merge(vector<Spices*>& allSpices, int start, int middle, int end);
};

#endif