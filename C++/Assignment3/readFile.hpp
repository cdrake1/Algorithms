//header file for readFile
#ifndef READFILE_HPP
#define READFILE_HPP

#include <vector>
#include <string>

using namespace std;

class readFile{
    public:
        vector<string> readMagicItems(); //reads magicitems.txt into a vector when called
        vector<string> readFindMagicItems(); //reads magicitems-bst.txt into a vector when called
        void readGraph();
};

#endif
