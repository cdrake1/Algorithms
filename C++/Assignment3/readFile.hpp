//header file for readFile
#ifndef READFILE_HPP
#define READFILE_HPP

#include "Graphs.hpp"
#include "Vertex.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class readFile{
    public:
        vector<string> readMagicItems(); //reads magicitems.txt into a vector when called
        vector<string> readFindMagicItems(); //reads magicitems-bst.txt into a vector when called
        void readGraph(); //reads the graphs1.txt
};

#endif
