//header file for graphs
#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include "Vertex.hpp"
#include "QNode.hpp"
#include "Edge.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Graphs{
    public:
        Graphs(); //graph constructor
        void addVertex(string id); //adds a vertex to the graph
        void addEdge(string from, string to, string cost); //adds an edge to the graph
        Vertex* findVertexByID(string id); //find vertex by given id
        vector<Vertex*> graph; //vector of vertex pointers / graph object
        vector<Edge*> edges; //vector to store all edges
        void bellManFord();
        void singleSource();
        void relax(); //finds shorter path
};

#endif