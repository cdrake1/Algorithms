//header file for knapsack and spices
#ifndef SPICES_HPP
#define SPICES_HPP

#include <string>
#include <vector>

using namespace std;

class Spices{
    public:
    Spices(string name, double price, int qty); //spice constructor
    //name, price, and qty of the spices
    string spiceName; 
    double unitPrice;
    int spiceQty;
    double totalPrice;
};

#endif