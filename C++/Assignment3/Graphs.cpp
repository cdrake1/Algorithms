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
        cout << "One or both vertices not found\n";
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

void Graphs::printAdjacencyList(){ //graph object adjacency list
    //outputs the graph object as an adjacency list
    for(int i = 0; i < graph.size(); i++){
        cout<< "[" << graph[i]->id << "]" << " ";
        for (int j = 0; j < graph[i]->neighbors.size(); j++)
        {
            cout<< graph[i]->neighbors[j]->id << " ";
        }
        cout<< "\n";
    }
}

void Graphs::Matrix(){ //graph object matrix
    //creates a 2d array and populates it with all dots
    string matrix[graph.size()+1][graph.size()+1];
    for(int row = 0; row < graph.size()+1; row++){
        for(int col = 0; col < graph.size()+1; col++){
            matrix[row][col] = ".";
        }
    }
    //populates matrix with vertex ids
    for (int i = 1; i < graph.size() + 1; i++) {
        matrix[i][0] = graph[i - 1]->id;
        matrix[0][i] = graph[i - 1]->id;
    }
    //populates matrix with edges
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i]->neighbors.size(); j++){
            string id2 = graph[i]->neighbors[j]->id;
            matrix[stoi(graph[i]->id)][stoi(id2)] = "x";
        }
    }
    //outputs matrix
    for(int row = 0; row < graph.size() + 1; row++){
        for(int col = 0; col < graph.size() + 1; col++){
            cout<< matrix[row][col] << " ";
        }
        cout<< "\n";
    }
}