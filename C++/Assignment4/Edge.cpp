//This file creates the Edge class
//For use with weighted and directed graphs
#include "Edge.hpp"

Edge::Edge(Vertex* from, Vertex* to, string cost){ //edge class constructor
    this->to = to;
    this->from = from;
    this->cost = cost;
}