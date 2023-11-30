//This file reads lines of a txt
#include "readFile.hpp"

void readFile::readGraph(){ //reads graph file
    //opens file
    string line;
    fstream graphFile;
    graphFile.open("graphs2.txt");

    //initializes graph
    Graphs graphFun;

    if(graphFile.is_open()){
        //if file open iterate through line by line
        while(getline(graphFile, line)){
            //check if the line contains new graph
            if(line.find("new graph") != string::npos || graphFile.eof()){
                //check if there is already a graph object, process it, delete it
                if(graphFun.graph.size() > 0){
                    //delete pointers in old graph and clear it/resize it
                    for (int i = 0; i < graphFun.graph.size(); i++){
                        Vertex* vertex = graphFun.graph[i];
                        delete vertex;
                    }
                    graphFun.graph.clear();
                    graphFun.graph.resize(0);
                    //delete pointers to all the edges. clear it and resize it
                    for (int i = 0; i < graphFun.edges.size(); i++){
                        Edge* edge = graphFun.edges[i];
                        delete edge;
                    }
                    graphFun.edges.clear();
                    graphFun.edges.resize(0);
                }
            }
            //check if the line contains 'add vertex'
            else if(line.find("add vertex") != string::npos){
                //create a string stream to iterate through the line
                stringstream str(line);
                string iterator;
                string vertex;
                while(str >> iterator){
                    //if the sub string is not 'add' and 'vertex' then its the vertex id
                    if(iterator != "add" && iterator != "vertex"){
                        vertex = iterator;
                    }
                }
                //add the new vertex
                graphFun.addVertex(vertex);
            }
            //check if the line contains 'add edge'
            else if(line.find("add edge") != string::npos){
                //create string stream, iterator, edge variables, and a cost variable
                stringstream str(line);
                string iterator;
                string edge1;
                string edge2;
                string cost;
                //flag to switch to other edge
                bool isEdge1 = true;
                bool isEdge2 = false;
                while(str >> iterator){
                    //check if substring is the vertex id's
                    if(iterator != "add" && iterator != "edge" && iterator != "-"){
                        if(isEdge1 && !isEdge2){
                            edge1 = iterator;
                            isEdge1 = false;
                            isEdge2 = true;
                        }
                        else if(isEdge2 && !isEdge1){
                            edge2 = iterator;
                        }
                        else{
                            //add edges and then reset the variables
                            cost = iterator;
                            graphFun.addEdge(edge1, edge2, cost);
                            edge1.clear();
                            edge2.clear();
                            cost.clear();
                            isEdge1 = true;
                            isEdge2 = false;
                        }
                    }
                }
            }
        }
        //close file and output feedback
        graphFile.close();
        cout << "graph file read correctly \n";
    }
    else{
        //output if there is an error with the file
        cout<< "Something went wrong when trying to open the file \n";
    }
}

void readFile::readKnapSack(){ //reads spice.txt
    //opens file
    string line;
    fstream spiceFile;
    spiceFile.open("spice.txt");

    if(spiceFile.is_open()){
        //if file open iterate through line by line
        while(getline(spiceFile, line)){
            //check if the line contains new graph
            if(line.find("spice name") != string::npos){
                stringstream str(line);
                string iterator;
                string name;
                double price;
                int quantity;

                int count = 0;

                while(str >> iterator){
                    if(iterator != "spice" && iterator != "name" && iterator != "=" && iterator != "qty" && iterator != "total_price"){
                        if(count == 0){
                            name = iterator;
                            count++;
                        }
                        else if(count == 1){
                            price = stod(iterator);
                            count++;
                        }
                        else{
                            quantity = stoi(iterator);

                        }
                    }
                }
            
            }
        }
        //close file and output feedback
        spiceFile.close();
        cout << "spice file read correctly \n";
    }
    else{
        //output if there is an error with the file
        cout<< "Something went wrong when trying to open the file \n";
    }

}