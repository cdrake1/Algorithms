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

    Stack myStack;
    Queue myQueue;

    for (string line : magicItems) {
        bool isOrIsnt = true;
        for(int i = 0; i < line.length(); i++){
            myStack.push(line.at(i));
            myQueue.enqueue(line.at(i));
        }
        while(!myStack.isEmpty() && !myQueue.isEmpty()){
            char stackChar = myStack.pop();
            char queueChar = myQueue.dequeue();
            if(stackChar != queueChar){
                isOrIsnt = false;
                break;
            }
        }
        if(isOrIsnt){
            cout << line;
        }
    }
    return 0;
}