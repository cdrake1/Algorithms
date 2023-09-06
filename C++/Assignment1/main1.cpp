//main file to run assignment 1 folder
#include "readFile.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    cout << "start \n";
    readFile reader;
    vector<string> magicItems = reader.readInto();

    cout << "Done \n";

    for (string line : magicItems) {
        cout << line << "\n";
    }
    return 0;
}