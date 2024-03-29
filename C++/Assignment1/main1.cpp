//main file to run assignment 1 folder
//rebuild progam1 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
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
            cout << line << "\n";
        }
    }

    // sorts and shuffling
    Sorts sorts;
    int mComparisons = 0; //merge sort comparisons counter
    int qComparisons = 0; //quick sort comparisons counter

    //call sorts/shuffles and pass magicItems
    sorts.selectionSort(magicItems);
    sorts.knuthShuffle(magicItems);
    sorts.insertionSort(magicItems);
    sorts.knuthShuffle(magicItems);
    sorts.mergeSort(magicItems, 0, magicItems.size() - 1, mComparisons);
    sorts.knuthShuffle(magicItems);
    sorts.quickSort(magicItems, 0, magicItems.size() - 1, qComparisons);

    cout<<"Merge sort comparisons: " << mComparisons << "\n";
    cout<<"Quick sort comparisons: " << qComparisons << "\n";
    return 0;
}