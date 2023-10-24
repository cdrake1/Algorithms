//header file for hashing and chaining
#ifndef HASHING_HPP
#define HASHING_HPP

using namespace std;

class HashTable{
    public:
        HashTable(); //constructor

        void put(); //add element

        void get(); //get element


    private:
        void hashFunction(); //hashing function
};



#endif