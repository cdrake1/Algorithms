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

bool Graphs:: bellmanFord(Vertex* source){
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
    for(int i = 0; i < graph.size(); i++){
        graph[i]->distance = maxInt;
        graph[i]->predecessor = nullptr;
    }
}

void Graphs::relax(Edge* edge) {
    //relaxes edge and find shorter path
    if (edge->to->distance > edge->from->distance + edge->cost) {
        edge->to->distance = edge->from->distance + edge->cost;
        edge->to->predecessor = edge->from;
    }
}

void Graphs::outputSSSPResults() { //check
    for (Vertex* vertex : graph) {
        cout << "1 -> " << vertex->id << " cost is " << vertex->distance << "; path is ";

        Stack stack;
        Vertex* currentVertex = vertex;
        while (currentVertex != nullptr) {
            stack.push(currentVertex->id);
            currentVertex = currentVertex->predecessor;
        }

        while (!stack.isEmpty()) {
            cout << stack.pop();
            if (!stack.isEmpty()) {
                cout << " -> ";
            }
        }
        cout << "." << endl;
    }
    cout << "\n";
}
