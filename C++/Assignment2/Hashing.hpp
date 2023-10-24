//header file for hashing and chaining
#ifndef HASHING_HPP
#define HASHING_HPP

using namespace std;

class HashTable{
    public:
        HashTable(); //constructor

        void put(string key, string value); //add element

        string get(string key); //get element

        bool contains(string key); //checks if the element is in the hash table


    private:
        void hashFunction(); //hashing function
};



#endif