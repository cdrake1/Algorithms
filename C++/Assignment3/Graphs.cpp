//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){ //graph object constructor
    //clears vector and resizes it to 0
    graph.clear();
}

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

void Graphs::Matrix(){ //graph object matrix
    //create matrix of graph size and populate with vertex
    string graphMatrix[graph.size()+1][graph.size()+1];
    for(int row = 0; row < graph.size() + 1; row++){
        for(int col = 0; col < graph.size() + 1; col++){
            graphMatrix[row][col] = "0";
        }
    }

    for(int row = 1; row < graph.size() + 1; row++){
        graphMatrix[row][0] = graph[row - 1]->id;
    }
    for(int col = 1; col < graph.size() + 1; col++){
        graphMatrix[0][col] = graph[col - 1]->id;
    }

    for(int i = 0; i < graph.size(); i++){

    }
}