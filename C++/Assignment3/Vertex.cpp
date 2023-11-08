//This file creates the Vertex class
//For use with graphs
#include "Vertex.hpp"


Vertex::Vertex(string id){ //vertex class constructor
    this->id = id;
    this->processed = false;
    this->neighbors;
}