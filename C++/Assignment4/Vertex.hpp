//header file for vertex creation
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "Edge.hpp"

#include <string>
#include <vector>

using namespace std;

class Vertex{
    public:
    Vertex(string id); //vertex constructor
    string id; //vertex number
    bool processed; //visited
    vector<Edge*> neighbors; //connected vertex's
};

#endif
