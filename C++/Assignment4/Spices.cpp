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
    capacity = capacity;
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


void Knapsack:: fractionalKnapsack(){ //fractional knapsack algorithm
    greatestUnitPrice();

}