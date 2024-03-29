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

Vertex* Graphs::findVertexByID(string id){ //searches the graph object for a given vertex
    //returns the pointer to the vertex within the graph object
    for(int i = 0; i < graph.size(); i++){
        if(graph[i]->id == id){
            return graph[i];
        }
    }
    return nullptr;
}

bool Graphs:: bellmanFord(){ //sssp algorithm
    //create source vertex pointer
    Vertex* source = graph[0];
    //call initialize function
    initSSSP(source);
    //iterate through all vertices in the graph
    for(int i = 0; i < graph.size() - 1; i++){
        //for each edge in the graph call relax
        for(int j = 0; j < edges.size(); j++){
            Edge* edge = edges[j];
            //call relax
            relax(edge);
        }
    }
    //check for negative cycles
    for(int k = 0; k < edges.size(); k++){
        Edge* edge = edges[k];
        if(edge->to->distance > edge->from->distance + edge->cost){
            return false;
        }
    }
    return true;
}

void Graphs:: initSSSP(Vertex* source){ //initialize everything
    for(int i = 0; i < graph.size(); i++){
        //for each vertex clear its predecessors and set its distance to large int
        Vertex* vertex = graph[i];
        vertex->distance = 8675309;
        vertex->predecessor = nullptr;
    }
    //source vertex has a distance of zero
    source->distance = 0;
}

void Graphs:: relax(Edge* edge){ //relax edges
    //add edges to predecessor vector
    if (edge->to->distance > edge->from->distance + edge->cost) {
        edge->to->distance = edge->from->distance + edge->cost;
        edge->to->predecessor = edge->from;
    }
}


void Graphs:: outputSSSPResults(){ //output the results of the sssp algorithm
    //create stack
    Stack stack;
    for (int i = 1; i < graph.size(); i++) {
        //iterate through all vertices with current Vertex and counters to help with formatting output
        cout << graph[0]->id << " -> " << graph[i]->id << " cost is " << graph[i]->distance << "; ";
        Vertex* current = graph[i];
        int countOne = 0;
        int countTwo = 0;
        while(current != nullptr){
            stack.push(current->id);
            current = current->predecessor;
            countOne++;
        }
        //output based on position
        cout << "path: ";
        while(!stack.isEmpty()){
            string prev = stack.pop();
            if(countTwo == countOne - 1){
                cout << prev; 
            }
            else{
                cout << prev << " -> "; 
                countTwo++;
            }
        }
        cout << "\n";
    }
    cout << "\n";
}