// This file creates the spices class
#include "Spices.hpp"

Spices:: Spices(string name, double price, int qty){ //spice class constructor
    spiceName = name;
    totalPrice = price;
    spiceQty = qty;
    unitPrice = price / qty;
    processed = false;
}

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
    //output contents of the knapsack
    cout << "Knapsack of capacity " << knapCapacity << " is worth " << priceTotal << " and contains:\n";
    for (int i = 0; i < items.size(); i++) {
        cout << items[i]->spiceName << " - " << items[i]->spiceQty << " units\n";
    }
}