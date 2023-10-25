//header file for hashing and chaining
#ifndef HASHING_HPP
#define HASHING_HPP

#include "Node.hpp"

#include <vector>
#include <string>

using namespace std;

class HashTable{
    public:
        HashTable(); //constructor

        void put(string input); //adds to the hash table

        int get(string key); //retrieves a value from the hash table

        vector<Node*> hashTable; //vector of node pointers

        int hashTableSize; //size of hash table

    private:
        int hashFunction(string input); //hashing function
};

#endif