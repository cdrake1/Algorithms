//This file reads lines of a txt into a String vector
#include "readFile.hpp"

vector<string> readFile :: readMagicItems() { //reads magic items into a vector
    string line;
    vector<string> fileLines;

    fstream magicFile;
    magicFile.open("magicitems.txt"); //open file

    if(magicFile.is_open()){ //check if file is open, remove spaces, and make each letter lowercase, then add it to vector
        while(getline(magicFile, line)){
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            for(int i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]);
            }
            fileLines.push_back(line); //push onto the end of the vector
        }
        magicFile.close(); //close file
        cout << "Magic items file read correctly \n";
    }
    else{ //error checking
        cout << "Something went wrong when trying to open the file \n";
    }
    return fileLines;
}

vector<string> readFile:: readFindMagicItems(){ //reads magic items BST into a vector
    string line;
    vector<string> fileLines;

    fstream magicFile;
    magicFile.open("magicitems-bst.txt"); //open file

    if(magicFile.is_open()){ //check if file is open, remove spaces, and make each letter lowercase, then add it to vector
        while(getline(magicFile, line)){
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            for(int i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]);
            }
            fileLines.push_back(line); //push onto the end of the vector
        }
        magicFile.close(); //close file
        cout << "Magic BST file read correctly \n";
    }
    else{ //error checking
        cout << "Something went wrong when trying to open the file \n";
    }
    return fileLines;
}

void readFile::readGraph(){ //reads graph file in and creates 3 different versions of a graph
    //opens file
    string line;
    fstream graphFile;
    graphFile.open("graphs1.txt");

    //initializes graph
    Graphs graphFun;

    if(graphFile.is_open()){
        //if file open iterate through line by line
        while(getline(graphFile, line)){
            //check if the line contains new graph
            if(line.find("new graph") != string::npos || graphFile.eof()){
                //check if there is already a graph object, process it, delete it
                if(graphFun.graph.size() > 0){
                    //output matrix
                    graphFun.Matrix();
                    cout<< "\n";
                    //output adjacency list
                    graphFun.printAdjacencyList();
                    cout<< "\n";
                    //output depth-first traversal
                    cout << "depth-first search:" << "\n";
                    graphFun.depthFirst(graphFun.graph[0]);
                    cout<<"\n";
                    //output breadth-first traversal
                    cout << "breadth-first search:" << "\n";
                    graphFun.breadthFirst(graphFun.graph[0]);
                    cout<<"\n";
                    //delete pointers in old graph and clear it/resize it
                    for (int i = 0; i < graphFun.graph.size(); i++){
                        Vertex* vertex = graphFun.graph[i];
                        delete vertex;
                    }
                    graphFun.graph.clear();
                    graphFun.graph.resize(0);
                }
            }
            //check if the line contains 'add vertex'
            else if(line.find("add") != string::npos && line.find("vertex") != string::npos){
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
            else if(line.find("add") != string::npos || line.find("edge") != string::npos){
                //create string stream, iterator, and edge variables
                stringstream str(line);
                string iterator;
                string edge1;
                string edge2;
                //flag to switch to other edge
                bool isEdge1 = true;
                while(str >> iterator){
                    //check if substring is the vertex id's
                    if(iterator != "add" && iterator != "edge" && iterator != "-"){
                        if(isEdge1){
                            edge1 = iterator;
                            isEdge1 = false;
                        }
                        else{
                            //add edges and then reset the variables
                            edge2 = iterator;
                            graphFun.addEdge(edge1, edge2);
                            edge1.clear();
                            edge2.clear();
                            isEdge1 = true;
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