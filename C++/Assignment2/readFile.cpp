//This file reads lines of a txt into a String vector
//here is the path to the file: /Users/xperiencedbum/Downloads/magicitems.txt
#include "readFile.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

vector<string> readFile :: readInto() {
    
    string filePath;
    string line;
    vector<string> fileLines;

    cout << "Enter the path of the file: "; //grab user input for file path
    cin >> filePath;

    fstream magicFile;
    magicFile.open(filePath); //open file

    if(magicFile.is_open()){ //check if file is open, remove spaces, and make each letter lowercase, then add it to vector
        while(getline(magicFile, line)){
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            for(int i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]);
            }
            fileLines.push_back(line); //push onto the end of the vector
        }
        magicFile.close(); //close file
        cout << "File read correctly \n";
    }
    else{ //error checking
        cout << "Something went wrong when trying to open the file \n";
    }
    return fileLines;
}