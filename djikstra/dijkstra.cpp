#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int node_count;
string startNodeId;
string endNodeId;
const char* WHITESPACE = " \t\r";



string trim(string s){
    //ltrim
    auto i = s.find_first_not_of(WHITESPACE);
    s = (i == string::npos) ? s : s.substr(i);

    //rtrim
    i = s.find_last_not_of(WHITESPACE);
    s = (i == string::npos) ? s : s.substr(0, i);
    return s;
}

struct Node{
    Node(string s = "") : id(s), predecessor(nullptr) { 
        estimate = (s == startNodeId) ? 0.0 : __DBL_MAX__;
    }

    bool operator==(const Node& rhs){
        return rhs.id == id;
    }

    void addAdjacency(pair<Node, double> p){
        adjacencies.push_back(p);
    }

    vector<pair<Node, double>> adjacencies;
    double estimate;
    string id;
    Node* predecessor;
};

struct NodeCompare{
    bool operator()(Node& l, Node& r) const{
        return l.estimate > r.estimate;
    }
};

int main(int argc, char *argv[]){    
    ifstream file(argv[1]);
    vector<Node> nodes;
    vector<pair<string, double>> edges;
    vector<Node> visitedNodes;
    int nodeCount = -1;
    string line = "";   

    /** READ IN LINES AND BUILD NODES */
    while(getline(file, line)){
        if(nodeCount < 0)
            nodeCount = stoi(line);

        else{
            stringstream ss(trim(line));
            string nodeId;
            double weight;
            
            ss >> nodeId;
            nodes.push_back(Node(nodeId));

            while(ss >> nodeId >> weight)
                nodes[nodes.size() - 1].addAdjacency(pair<Node, double>(Node(nodeId), weight));          
        }
    }

    file.close();

    // Fill min priority queue
    priority_queue<Node&, vector<Node&>, NodeCompare> Q = priority_queue<Node&, vector<Node&>, NodeCompare>(nodes.begin(), nodes.end());

    while(!Q.empty()){
        vector<Node> visited;
        Node current = Q.top();
        
        for(auto a : current.adjacencies){
            auto v = visited.begin();

            while(v != visited.end()){
                if(*v == a.first)
                    break;
                v++;
            }

            if(v != visited.end()){
                for(auto n : nodes){
                    if(n == a.first && a.first.estimate > (current.estimate + current.))
                }
            }
        }

        Q.pop();
        visited.push_back(current);

        if(current.id == startNodeId)
            break;
    }
    
    return 0;
}