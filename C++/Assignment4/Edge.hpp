//header file for edge creation
#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

#include <string>
#include <vector>

using namespace std;

class Edge{
    public:
    Edge(Vertex* from, Vertex* to, string cost); //edge constructor
    Vertex* from; //edge origin
    Vertex* to; //destination vertex
    string cost; //cost of getting there
};

#endif
