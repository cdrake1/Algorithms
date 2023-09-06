//This file reads lines of a txt into a String vector
#include "readFile.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readFile :: readFileIntoVector() {
    
    string filePath;
    string line;
    vector<string> fileLines;

    cout << "Enter the path of the file: ";
    cin >> filePath;

    fstream magicFile;
    magicFile.open(filePath);

    if(magicFile.is_open()){
        while(getline(magicFile, line)){
            //add to vector
        }
        magicFile.close();

    }
    else{
        cout << "Something went wrong when trying to open the file";
    }

    return fileLines;
};