//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){} //graph object constructor

void Graphs::addVertex(string id){ //add vertex to graph object
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(string from, string to, string cost){ //adds an edge to the graph object
    //finds the vertex's linked to the given ids
    Vertex* fromVertex = findVertexByID(from);
    Vertex* toVertex = findVertexByID(to);
    //creates a new edge
    Edge* newEdge = new Edge(fromVertex, toVertex, cost);
    //adds it to graph edge vector and to the source vertex
    edges.push_back(newEdge);
    fromVertex->neighbors.push_back(newEdge);
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