// This file creates the spices class
#include "Spices.hpp"

Spices:: Spices(string name, double price, int qty){
    spiceName = name;
    spicePrice = price;
    spiceQty = qty;
    totalPrice = price * qty;
}