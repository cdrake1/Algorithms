//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){
    graph.clear(); //clears vector and resizes it to 0
}


void Graphs::addVertex(string id){
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(string id1, string id2){
    findVertexByID(id1);
    findVertexByID(id2);

}
