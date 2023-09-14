//main file to run assignment 1 folder
//rebuild progam1 and run it by running: clang++ -o program1 main1.cpp readFile.cpp Node.cpp and then: ./program1 in terminal
#include "readFile.h"
#include "Node.h"

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
                break;
            }
        }
        if(isOrIsnt){ //if they match print out palindrome
            cout << line;
        }
    }
    return 0;
}