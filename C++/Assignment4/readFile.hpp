//header file for readFile
#ifndef READFILE_HPP
#define READFILE_HPP

#include "Graphs.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Spices.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class readFile{
    public:
        void readGraph(); //reads the graphs2.txt and creates weighted and directed graphs
        void readKnapSack(); //reads the spice.txt and creates knapsacks for the spices
        vector<Spices*> allSpices; //vector that holds all the spices
};

#endif
