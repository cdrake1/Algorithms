//header file for vertex creation
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>

using namespace std;

class Edge; //forward declaration to reference edge neighbors before class creation

class Vertex{ //vertex constructor
    public:
    Vertex(string id); //vertex constructor
    string id; //vertex number
    bool processed; //visited
    vector<Edge*> neighbors; //connected vertex's
};


class Edge{
    public:
    Edge(Vertex* from, Vertex* to, string cost); //edge constructor
    Vertex* from; //edge origin
    Vertex* to; //destination vertex
    string cost; //cost of getting there
};

#endif
