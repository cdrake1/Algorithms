//main file to run assignment 3 folder
//rebuild progam3 and run it by running: make followed by the exe name in terminal. To clean and rerun: make clean, make, followed by the exe name
#include "readFile.hpp"

using namespace std;

int main(){
    //create readfile instance and read text file into magic items
    readFile reader;
    vector<string> magicItems = reader.readInto();
}