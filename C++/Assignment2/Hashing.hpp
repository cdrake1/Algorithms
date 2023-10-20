#ifndef HASHING_HPP
#define HASHING_HPP

using namespace std;

class HashTable{
    public:
        HashTable(); //constructor

        void put(); //add element

        void get(); //get element

        void outputHashTable(); //print out all elements in hash

    private:
        void hashing(); //hashing function
};



#endif