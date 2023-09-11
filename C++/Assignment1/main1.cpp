//main file to run assignment 1 folder
//rebuild progam1 and run it by running: clang++ -o program1 main1.cpp readFile.cpp and ./program1 in terminal
#include "readFile.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    readFile reader;
    vector<string> magicItems = reader.readInto(); //we need to create an instance of the class to call it

    for (string line : magicItems) {
        cout << line << "\n";
    }
    return 0;
}