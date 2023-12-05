//This file creates the Graphs class
#include "Graphs.hpp"

Graphs::Graphs(){} //graph object constructor

void Graphs::addVertex(string id){ //add vertex to graph object
    //creates a new vertex and adds it to the graph
    Vertex* newVertex = new Vertex(id);
    graph.push_back(newVertex);
}

void Graphs::addEdge(string from, string to, int cost){ //adds an edge to the graph object
    //finds the vertex's linked to the given ids
    Vertex* fromVertex = findVertexByID(from);
    Vertex* toVertex = findVertexByID(to);
    //creates a new edge
    Edge* newEdge = new Edge(fromVertex, toVertex, cost);
    //adds it to graph edge vector and to the source vertex
    edges.push_back(newEdge);
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

bool Graphs:: bellmanFord(){
    Vertex* source = graph[0];
    initSSSP(source);
    //iterate through all vertices
    for(int i = 0; i < graph.size() - 1; i++){
        //for each edge
        for(Edge* edge: edges){
            //call relax
            relax(edge);
        }
    }
    //for each edge
    //check for cycles
    for(Edge* edge: edges){
        if(edge->to->distance > edge->from->distance + edge->cost){
            return false;
        }
    }
    return true;
}

void Graphs:: initSSSP(Vertex* source){
    //set distances
    //predecessor vertex
    //estimate of shortes path distance
    for(Vertex* vertex: graph){
        vertex->distance = 8675309;
        vertex->predecessor.clear();
    }
    source->distance = 0;
}

void Graphs::relax(Edge* edge) {
    // relaxes edge and sees if you can find a shorter path
    if (edge->to->distance > edge->from->distance + edge->cost) {
        edge->to->distance = edge->from->distance + edge->cost;
        edge->to->predecessor.push_back(edge->from);
    }
}


void Graphs::outputSSSPResults() {
    //output the results of the sssp algorithm
    Stack stack;
    for (int i = 1; i < graph.size(); i++) {
        cout << graph[0]->id << " -> " << graph[i]->id << " cost is " << graph[i]->distance << "; ";
        for (int j = 0; j < graph[i]->predecessor.size(); j++) {
            if(graph[i]->predecessor[j]->id == "1"){
                break; 
            }
            stack.push(graph[i]->predecessor[j]->id);
        }
        cout << " path is ";
        while(!stack.isEmpty()){
            cout << stack.pop() << " -> ";
        }
        cout << "\n";
    }
    cout << "\n";
}
