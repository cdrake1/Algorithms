//this file creates the hashing and chaining functions for a hashtable
#include "Hashing.hpp"
#include "Node.hpp"

#include <vector>
#include <string>
#include <stdexcept>

HashTable:: HashTable(){ //constructor function for hashtable
    vector<Node> hashTable; //create vector of linked lists
}

void HashTable:: put(string key, string value){ //add and element to the hashtable

}

string HashTable:: get(string key){ //grab and element from hashtable and return it
    if(!contains(key)){
        throw invalid_argument("Element does not exist");
    }

}

bool HashTable:: contains(string key){ //checks if an element is in the hash table

}

void HashTable:: hashFunction(){ //calculate hash value for given input

}