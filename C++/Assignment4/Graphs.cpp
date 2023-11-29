//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){} //graph object constructor

void Graphs::addVertex(string id){ //add vertex to graph object
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(string id1, string id2) {
    //get pointers to each vertex
    Vertex* vertex1 = findVertexByID(id1);
    Vertex* vertex2 = findVertexByID(id2);
    //check if they were not found
    if (vertex1 == nullptr || vertex2 == nullptr) {
        return;
    }
    //add neighbor for both vertex
    vertex1->neighbors.push_back(vertex2);
    vertex2->neighbors.push_back(vertex1);
}


Vertex* Graphs::findVertexByID(string id){ //searches the graph object for the given vertex id
    //returns the pointer to the vertex within the graph object
    for(int i = 0; i < graph.size(); i++){
        if(graph[i]->id == id){
            return graph[i];
        }
    }
    return nullptr;
}

void Graphs::bellManFord(){
    singleSource();
}