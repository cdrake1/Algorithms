#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



class readFile {
    public:
        readFile(){
            string filePath;
            string line;
            vector<string> fileLines;
            cout << "Enter the path of the file: ";
            cin >> filePath; //grab user input for file path

            ifstream magicfile(filePath); //create version of file
            if(magicfile.is_open()){

            }
            else{
                cout << "Something went wrong when trying to open the file";
            }

        }

};