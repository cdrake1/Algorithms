// This file creates the spices class
#include "Spices.hpp"

Spices:: Spices(string name, double price, int qty){
    spiceName = name;
    totalPrice = price;
    spiceQty = qty;
    unitPrice = price / qty;
}