//this file reads lines of the graph2.txt and spice.txt files
#include "readFile.hpp"

//graphs, vertices, and edges-------------

void readFile::readGraph(){ //reads graph file
    //opens file
    string line;
    fstream graphFile;
    graphFile.open("graphs2.txt");

    //initializes graph
    Graphs graphFun;

    if(graphFile.is_open()){
        //if file open iterate through line by line and check if the line contains new graph
        while(getline(graphFile, line)){
            if(line.find("new graph") != string::npos){
                //check if there is already a graph object, process it, delete it
                if(graphFun.graph.size() > 0){
                    bool answer = graphFun.bellmanFord();
                    graphFun.outputSSSPResults();
                    //delete pointers for old graph and all edges. Clear and resize vectors
                    for(int i = 0; i < graphFun.graph.size(); i++){
                        Vertex* vertex = graphFun.graph[i];
                        delete vertex;
                    }
                    graphFun.graph.clear();
                    for (int i = 0; i < graphFun.edges.size(); i++){
                        Edge* edge = graphFun.edges[i];
                        delete edge;
                    }
                    graphFun.edges.clear();
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
                int cost;
                //flag to switch to other edge
                bool isEdge1 = true;
                bool isEdge2 = false;
                while(str >> iterator){
                    if(iterator != "add" && iterator != "edge" && iterator != "-"){
                        if(edge1.empty()){
                            edge1 = iterator;
                        } 
                        else if(edge2.empty()){
                            edge2 = iterator;
                        } 
                        else{
                            cost = stoi(iterator);
                            graphFun.addEdge(edge1, edge2, cost);
                            edge1.clear();
                            edge2.clear();
                            cost = 0;
                        }
                    }
                }
            }
        }
        //process and output last graph
        if(graphFile.eof()){
            Vertex* sourceVertex = graphFun.graph[0];
            bool answer = graphFun.bellmanFord();
            graphFun.outputSSSPResults();
            //delete pointers in old graph and clear it/resize it
            for(int i = 0; i < graphFun.graph.size(); i++){
                Vertex* vertex = graphFun.graph[i];
                delete vertex;
            }
            graphFun.graph.clear();
            //delete pointers to all the edges. clear it and resize it
            for (int i = 0; i < graphFun.edges.size(); i++){
                Edge* edge = graphFun.edges[i];
                delete edge;
            }
            graphFun.edges.clear();
        }
        //close file and output feedback
        graphFile.close();
        cout << "graph file read correctly \n";
    }
    else{
        //output if there is an error with the file
        cout << "Something went wrong when trying to open the file \n";
    }
}

//spices and knapsacks-------------

void readFile::readKnapSack(){ //reads spice.txt
    //opens file
    string line;
    fstream spiceFile;
    spiceFile.open("spice.txt");

    //creates version of knapsack and flag
    Knapsack* knapsack = nullptr;
    bool knapsackCreated = false;

    if(spiceFile.is_open()){
        //if file open iterate through line by line
        while(getline(spiceFile, line)){
            //check if the line contains spice name
            if(line.find("spice name") != string::npos){
                //create variables for spice information
                stringstream str(line);
                string iterator;
                string name;
                double price;
                int quantity;
                int count = 0;
                //iterate through string by string
                while(str >> iterator){
                    if(iterator != "spice" && iterator != "name" && iterator != "=" && iterator != "qty" && iterator != "total_price"){
                        //grab the name, price, and quantity of each spice
                        if(count == 0){
                            //trim semicolon off end
                            iterator.erase(std::remove(iterator.begin(), iterator.end(), ';'), iterator.end());
                            name = iterator;
                            count++;
                        }
                        else if(count == 1){
                            iterator.erase(std::remove(iterator.begin(), iterator.end(), ';'), iterator.end());
                            price = stod(iterator);
                            count++;
                        }
                        else{
                            iterator.erase(std::remove(iterator.begin(), iterator.end(), ';'), iterator.end());
                            quantity = stoi(iterator);
                        }
                    }
                }
                //create spice and add it to the spice array
                Spices* spice = new Spices(name, price, quantity);
                allSpices.push_back(spice);
            }
            //check for knapsack capacity or the end of the file
            else if(line.find("knapsack capacity") != string::npos){
                //check if knapsack is created
                if(!knapsackCreated){
                    //if not created grab capacity and create knapsack
                    stringstream str(line);
                    string iterator;
                    double capacity;
                    while(str >> iterator){
                        if(iterator != "knapsack" && iterator != "capacity" && iterator != "="){
                            iterator.erase(std::remove(iterator.begin(), iterator.end(), ';'), iterator.end());
                            capacity = stod(iterator);
                            break;
                        }
                    }
                    //create knapsack and change flag
                    knapsack = new Knapsack(capacity);
                    knapsackCreated = true;
                }
                //if knapsack is already created
                else{
                    //output old and delete it
                    knapsack->fractionalKnapsack(allSpices);
                    cout << "\n";
                    knapsack->clearKnapsack();
                    //create new knapsack
                    stringstream str(line);
                    string iterator;
                    double capacity;
                    while(str >> iterator){
                        if(iterator != "knapsack" && iterator != "capacity" && iterator != "="){
                            iterator.erase(std::remove(iterator.begin(), iterator.end(), ';'), iterator.end());
                            capacity = stod(iterator);
                            break;
                        }
                    }
                    delete knapsack;
                    knapsack = new Knapsack(capacity);
                }
            }
        }
        //check if file is at the end
        if(spiceFile.eof()){
            //output last knapsack and delete it
            knapsack->fractionalKnapsack(allSpices);
            knapsack->clearKnapsack();
            delete knapsack;
        }
        //close file and output feedback
        spiceFile.close();
        cout << "\n";
        cout << "spice file read correctly \n";
        cout << "\n";
    }
    else{
        //output if there is an error with the file
        cout<< "Something went wrong when trying to open the file \n";
    }
}