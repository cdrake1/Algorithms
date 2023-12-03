//This file creates the Vertex and edge classes
//For use with graphs
#include "Vertex.hpp"

//Vertex class below------------

Vertex::Vertex(string id){ //vertex class constructor
    this->id = id;
    this->processed = false;
}

//Edge class below------------

Edge::Edge(Vertex* from, Vertex* to, string cost){ //edge class constructor
    this->to = to;
    this->from = from;
    this->cost = cost;
}