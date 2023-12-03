//header file for graphs
#ifndef GRAPHS_HPP
#define GRAPHS_HPP

#include "Vertex.hpp"
#include "Node.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Graphs{
    public:
        Graphs(); //graph constructor
        void addVertex(string id); //adds a vertex to the graph
        void addEdge(string from, string to, int cost); //adds an edge to the graph
        Vertex* findVertexByID(string id); //find vertex by given id
        vector<Vertex*> graph; //vector of vertex pointers / graph object
        vector<Edge*> edges; //vector to store all edges

        bool bellmanFord(Vertex* s); //bellman ford sssp algorithm
        void initSSSP(Vertex* S); //initialize distances
        void relax(Edge* edge); //relax edges
        int maxInt = 20490072023; //max int num
        void outputSSSPResults(); //outputs the results of each graph
};

#endif