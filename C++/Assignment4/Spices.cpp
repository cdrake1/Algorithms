// This file creates the spices class
#include "Spices.hpp"

//Spices class below------------

Spices:: Spices(string name, double price, int qty){ //spice class constructor
    spiceName = name;
    totalPrice = price;
    spiceQty = qty;
    unitPrice = price / qty;
    processed = false;
}

//Knapsack class below----------

Knapsack:: Knapsack(double capacity){ //knapsack class constructor
    knapCapacity = capacity;
}

void Knapsack:: addItem(Spices* spice){ //add an item to the knapsack
    items.push_back(spice);
}

void Knapsack::clearKnapsack() { //clear the items stored in the knapsack
    for (Spices* spice : items) {
        delete spice;
    }
    items.clear();
}


void Knapsack:: fractionalKnapsack(vector<Spices*> allSpices){ //fractional knapsack algorithm
    //keep track of current weight and the price of the knapsack
    double currentWeight = 0;
    double priceTotal = 0;
    //sort by unit price high to low
    Sorts sort;
    sort.mergeSort(allSpices, 0, allSpices.size() - 1);
    //iterate through spice array
    for(int i = 0; i < allSpices.size(); i++){
        //check if the current spice can completely fit in the knapsack
        if(currentWeight + allSpices[i]->spiceQty <= knapCapacity){
            //add the entire spice to the knapsack
            currentWeight += allSpices[i]->spiceQty;
            priceTotal += allSpices[i]->totalPrice;
            addItem(allSpices[i]);
        }
        //else add a fraction of the spice
        else{
            double remaining = knapCapacity - currentWeight;
            double fraction = remaining / allSpices[i]->spiceQty;
            priceTotal += allSpices[i]->totalPrice * fraction;
            //create a new spice object with the fraction and add it to the knapsack
            Spices* fractionSpice = new Spices(allSpices[i]->spiceName, allSpices[i]->totalPrice * fraction, remaining);
            addItem(fractionSpice);
            currentWeight = knapCapacity;
        }
    }
    //check how many items and output contents of the knapsack
    cout << "Knapsack of capacity " << knapCapacity << " is worth " << priceTotal << " quatloos and contains ";
    for(int i = 0; i < items.size(); i++){
        if(i == items.size() - 1){
            cout << "and " << items[i]->spiceQty << " scoop of " << items[i]->spiceName << "\n";

        }
        else{
            cout << items[i]->spiceQty << " scoop of " << items[i]->spiceName << ", ";
        }
    }
}

//Sorts class below-----------

//merge sort to sort spice vector
void Sorts:: mergeSort(vector<Spices*>& allSpices, int start, int end){
    if(start >= end){
        return;
    }
    //find middle point, sort left, sort right, and merge the sorted arrays
    int middle = (start + end) / 2;
    mergeSort(allSpices, start, middle);
    mergeSort(allSpices, middle + 1, end);
    merge(allSpices, start, middle, end);
}

//merge sorted arrays together
void Sorts:: merge(vector<Spices*>& allSpices, int start, int middle, int end){
    //declare left and right pointers, subArray
    int left = start;
    int right = middle + 1;
    vector<Spices*> subVec(end - start + 1);

    //iterate through sub array
    for(int i = 0; i < end - start + 1; i++){
        if(right > end){
            //add element from left side
            subVec[i] = allSpices[left];
            left++;
        }
        else if (left > middle)
        {
            //add element from right side
            subVec[i] = allSpices[right];
            right++;
        }
        else if (allSpices[left]->unitPrice >= allSpices[right]->unitPrice)
        {
            //add element from left side
            subVec[i] = allSpices[left];
            left++;
        }
        else{
            //add element from right side
            subVec[i] = allSpices[right];
            right++;
        }
    }
    //move subvector elements to main vector
    for(int j = 0; j < end - start + 1; j++){
        allSpices[start + j] = subVec[j];
    }
}