//main file to run assignment 1 folder
//rebuild progam2 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    readFile reader;
    vector<string> magicItems = reader.readInto(); //we need to create an instance of the class to call it

    for(string sentence : magicItems){
        cout<< sentence + "\n";
    }
}