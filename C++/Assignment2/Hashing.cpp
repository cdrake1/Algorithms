//this file creates the hashing and chaining functions for a hash table
#include "Hashing.hpp"

#include <vector>
#include <string>
#include <stdexcept>

//hash table constructor
HashTable:: HashTable(){
    this->hashTableSize = 250;

    //set each node to null and allocate memory for hash table
    hashTable.resize(hashTableSize, nullptr);
}

//adds a value to the hash table
void HashTable:: put(string input){
    //hash and find the index of input
    int hash = hashFunction(input);

    //create a new node with the given input
    Node* newNode = new Node(input);

    //check if hashed index contains other values (collision)
    if(hashTable[hash] == nullptr){ 
        //if there is no collision set new node to head
        hashTable[hash] = newNode;
    }
    else{ 
        //set next pointer to current head and set the head as the new node
        newNode->next = hashTable[hash];
        hashTable[hash] = newNode;
    }
}

//finds the given value in the hash table and returns the comparison count
int HashTable:: get(string key){
    //count comparisons for each get call
    int comparisons = 1;

    //hash and find the index of the target
    int hash = hashFunction(key);

    //temp node to iterate through linked list
    Node* current = hashTable[hash];

    //check if index is populated
    if(hashTable[hash] == nullptr){
        //throw exception if index is empty
        throw invalid_argument("This value is not in the hash table");
    }
    //if index is populated iterate through nodes
    else{
        //walk down list untl you find the value
        while(current != nullptr){
            comparisons++;
            if(current->val == key){
                break;
            }
            else{
                //if the current node is not the target move to the next
                current = current->next;
            }
        }
    }
    return comparisons;
}

//hashing function to find the hash code for the given input
int HashTable:: hashFunction(string input){
    //sum of ascii values
    int letterTotal = 0; 

    //finds the ascii value of each letter in the input
    for(int i = 0; i < input.length(); i++){
        char currentLetter = input[i];
        int asciiVal = int(currentLetter);
        letterTotal += asciiVal;
    }
    //find the hash code for the input and return it
    return (letterTotal % hashTableSize);
}