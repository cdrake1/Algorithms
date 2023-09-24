//main file to run assignment 1 folder
//rebuild progam1 and run it by running: clang++ -o program1 main1.cpp readFile.cpp Node.cpp Sorts.cpp and then: ./program1 in terminal
#include "readFile.hpp"
#include "Node.hpp"
#include "Sorts.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    readFile reader;
    vector<string> magicItems = reader.readInto(); //we need to create an instance of the class to call it

    Stack myStack; //create instances of stack and queue
    Queue myQueue;

    for (string line : magicItems) { //for each line in magic items push and enqueue each letter
        bool isOrIsnt = true;
        for(int i = 0; i < line.length(); i++){
            myStack.push(line.at(i));
            myQueue.enqueue(line.at(i));
        }
        while(!myStack.isEmpty() && !myQueue.isEmpty()){ //while stack and queue are not empty pop and dequeue
            char stackChar = myStack.pop();
            char queueChar = myQueue.dequeue();
            if(stackChar != queueChar){ //if they dont match break loop
                isOrIsnt = false;
            }
        }
        if(isOrIsnt == true){ //if they match print out palindrome
            cout << line + "\n";
        }
    }

    //Working before this point
    Sorts sortsAndShuffles;

    magicItems = sortsAndShuffles.knuthShuffle(magicItems); //after random
    sortsAndShuffles.selectionSort(magicItems);
    
    return 0;
}