//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){} //graph object constructor

void Graphs::addVertex(string id){ //add vertex to graph object
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(string id1, string id2){ //add an edge between graph vertex's
    findVertexByID(id1)->neighbors.push_back(findVertexByID(id2));
    findVertexByID(id2)->neighbors.push_back(findVertexByID(id1));
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

void Graphs::printAdjacencyList(){ //graph object adjacency list
    //outputs the graph object as an adjacency list
    for(int i = 0; i < graph.size(); i++){
        cout<< graph[i]->id << " ";
        for (int j = 0; i < graph[i]->neighbors.size(); j++)
        {
            cout<< graph[i]->neighbors[j];
        }
        cout<< "\n";
    }
}