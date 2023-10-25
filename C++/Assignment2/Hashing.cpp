//this file creates the hashing and chaining functions for a hashtable
#include "Hashing.hpp"
#include "Node.hpp"

#include <vector>
#include <string>
#include <stdexcept>

HashTable:: HashTable(int hashSize){
    this->hashSize = hashSize;
}

int HashTable:: hashFunction(string input){
    return input.length() % hashSize;
}