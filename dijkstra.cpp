#include "adjacencylist.h"
#include "string_opertions.h"
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace std::chrono;

struct Clock{
    void startTimer(){
        start = high_resolution_clock::now();
    }

    void finishTimer(string msg = ""){
        end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Time taken to " << msg << ": " << duration.count() << " microseconds" << endl;
    }

private:
    std::chrono::_V2::high_resolution_clock::time_point start;
    std::chrono::_V2::high_resolution_clock::time_point end;
};


int main(int argc, char *argv[]){    
    Clock timer;
    timer.startTimer();
    ifstream file(argv[1]);
    Graph g = Graph();
    int nodeCount = -1;
    string line = "";

    // Get starting timepoint
    

    //Initialize graph with file lines
    while(getline(file, line)){
        if(nodeCount < 0){
            nodeCount = stoi(line);
            g = Graph(nodeCount, argv[2]);
        }
        else{
            stringstream ss(trim(line));
            string nodeId = "";
            string nodeAdj = "";
            ss >> nodeId;
            getline(ss, nodeAdj);
            g.addNode(nodeId, nodeAdj);
        }
    }
    file.close();

    timer.finishTimer("initialize graph");
    timer.startTimer();
    // Fill min priority queue
    auto Q = g.V();
    timer.finishTimer("build queue");
    timer.startTimer();
    while(!Q.empty()){
        string connectedNodeId;
        string connectingWeight;
        GraphNode* currNode = Q.top();
        stringstream ss(currNode->adj);

        while(ss >> connectedNodeId >> connectingWeight)
            g.relax(currNode, connectedNodeId, stod(connectingWeight));
        
        Q.pop();
    }
    timer.finishTimer("run dijkstra");
    g.printPath(argv[3]);
    
    
    return 0;
}