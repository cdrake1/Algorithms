// This file creates the spices class
#include "Spices.hpp"

Spices:: Spices(string name, double price, int qty){ //spice class constructor
    spiceName = name;
    totalPrice = price;
    spiceQty = qty;
    unitPrice = price / qty;
}

Knapsack:: Knapsack(double capacity){
    capacity = capacity;
}

void Knapsack:: addItem(Spices* spice){
    items.push_back(spice);
}