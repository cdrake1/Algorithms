//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){} //graph object constructor

void Graphs::addVertex(string id){ //add vertex to graph object
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(Vertex* from, Vertex* to, int cost){ //adds an edge to the graph object
    //creates a new edge
    Edge* newEdge = new Edge(from, to, cost);
    //adds it to graph edge vector
    edges.push_back(newEdge);
    //iterates through graph object to add the edge to the source vertex
    for(int i = 0; i < graph.size(); i++){
        if(from == graph[i]){
            graph[i]->neighbors.push_back(newEdge);
        }
    }
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