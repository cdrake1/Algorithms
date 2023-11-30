//header file for knapsack and spices
#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>

using namespace std;

class Spices{
    public:
    Spices(string name, double price, int qty); //spice constructor
    string spiceName; //name, price, and qty of the spices
    double spicePrice;
    int spiceQty;
    double totalPrice;
};

#endif