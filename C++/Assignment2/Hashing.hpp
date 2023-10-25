//header file for hashing and chaining
#ifndef HASHING_HPP
#define HASHING_HPP

using namespace std;

class HashTable{
    public:
        HashTable(int hashSize); //constructor

        void put(string input); //add element

        string get(string key); //get element

        bool contains(string key); //checks if the element is in the hash table

        vector<Node> hashTable; //create vector of linked lists

        int hashSize; //size of the hash table

    private:
        int hashFunction(string input); //hashing function
};



#endif