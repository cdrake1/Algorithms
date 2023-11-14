//This file reads lines of a txt into a String vector
#include "readFile.hpp"

vector<string> readFile :: readMagicItems() { //reads magic items into a vector
    string line;
    vector<string> fileLines;

    fstream magicFile;
    magicFile.open("magicitems.txt"); //open file

    if(magicFile.is_open()){ //check if file is open, remove spaces, and make each letter lowercase, then add it to vector
        while(getline(magicFile, line)){
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            for(int i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]);
            }
            fileLines.push_back(line); //push onto the end of the vector
        }
        magicFile.close(); //close file
        cout << "Magic items file read correctly \n";
    }
    else{ //error checking
        cout << "Something went wrong when trying to open the file \n";
    }
    return fileLines;
}

vector<string> readFile:: readFindMagicItems(){ //reads magic items BST into a vector
    string line;
    vector<string> fileLines;

    fstream magicFile;
    magicFile.open("magicitems-bst.txt"); //open file

    if(magicFile.is_open()){ //check if file is open, remove spaces, and make each letter lowercase, then add it to vector
        while(getline(magicFile, line)){
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            for(int i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]);
            }
            fileLines.push_back(line); //push onto the end of the vector
        }
        magicFile.close(); //close file
        cout << "Magic BST file read correctly \n";
    }
    else{ //error checking
        cout << "Something went wrong when trying to open the file \n";
    }
    return fileLines;

}

void readFile::readGraph(){ //reads graph file in and creates 3 different versions of a graph
    //opens file
    string line;
    fstream graphFile;
    graphFile.open("graphs1.txt");

    //initializes graph
    Graphs graphFun;

    if(graphFile.is_open()){
        //if file open iterate through line by line
        while(getline(graphFile, line)){
            if(line.find("new graph")){
                if(graphFun.graph.size() > 0){
                    
                }
            }
            else if(line.find("add") && line.find("vertex")){

            }
            else if(line.find("add") && line.find("edge")){

            }
            else{
                
            }
        }
        graphFile.close(); //close file
        cout << "graph file read correctly \n";
    }
    else{
        //else there is an error with the file
        cout<< "Something went wrong when trying to open the file \n";
    }
}