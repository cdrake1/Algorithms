//header file for graphs
#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include "Vertex.hpp"
#include "QNode.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Graphs{
    public:
        Graphs(); //graph constructor
        void Matrix(); //creates a matrix
        void printAdjacencyList(); //outputs a graphs adjacency list
        void addVertex(string id); //adds a vertex to the graph
        void addEdge(string id1, string id2); //adds an edge to the graph
        Vertex* findVertexByID(string id); //find vertex by given id
        vector<Vertex*> graph; //vector of vertex pointers / graph object
        void depthFirst(Vertex* fromVertex); //traverses the graph depth-first
        void breadthFirst(Vertex* fromVertex); //traverses the graph breadth-first
        void resetProcessed(); //resets the processed flag for each vertex
};

#endif