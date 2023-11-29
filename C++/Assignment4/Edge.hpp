//header file for edge creation
#ifndef EDGE_HPP
#define EDGE_HPP

#include "Vertex.hpp"

#include <string>
#include <vector>

using namespace std;

class Edge{
    public:
    Edge(Vertex* from, Vertex* to, int cost); //edge constructor
    Vertex* from; //edge origin
    Vertex* to; //destination vertex
    int cost; //cost of getting there
};

#endif
