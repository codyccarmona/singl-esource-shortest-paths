#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct GraphNode{
    GraphNode(string i, string a, double e = __DBL_MAX__){
        id = i;
        adj = a;
        estimate = e;
        predecessor = nullptr;
    }

    GraphNode(const GraphNode& g){
        id = g.id;
        estimate = g.estimate;
        adj = g.adj;
        predecessor = g.predecessor;
    }

    bool operator==(const GraphNode& g) const{
        return g.id == id;
    }

    bool operator!=(const GraphNode& g) const{
        return g.id != id;
    }

    bool operator<(const GraphNode& rhs) const{
        return estimate < rhs.estimate;
    }

    bool operator>(const GraphNode& rhs) const{
        return estimate > rhs.estimate;
    }

    double getEstimate(){
        return estimate;
    }

    string getId(){
        return id;
    }

    void relax(GraphNode* node, double weight){
        if(estimate > node->estimate + weight){
            estimate = node->estimate + weight;
            predecessor = node;
        }
    }

    GraphNode* getPredecessor(){
        return predecessor;
    }

    ~GraphNode(){
        predecessor = nullptr;
    }
    string adj;
private:
    string id;
    double estimate;
    GraphNode* predecessor;
};

struct GraphNodeComparator{
    bool operator()(GraphNode* l, GraphNode* r) const{
        return l->getEstimate() > r->getEstimate();
    }
};
struct Graph{
    Graph() { }

    Graph(int m, string s) : maxsize(m), srcNodeId(s) { }

    Graph(const Graph& g){
        maxsize = g.maxsize;
        srcNodeId = g.srcNodeId;
        for(auto n : g.nodes)
            nodes.push_back(new GraphNode(*n));
    }

    void addNode(string nodeId, string nodeAdj){
        if(nodes.size() >= maxsize)
            return;

        if(nodeId == srcNodeId)
            nodes.push_back(new GraphNode(nodeId, nodeAdj, 0.0));
        else    
            nodes.push_back(new GraphNode(nodeId, nodeAdj));
    }

    void relax(GraphNode* src, string adjNodeId, double w){
        for(auto n : nodes){
            if(n->getId() == adjNodeId){
                n->relax(src, w);
                return;
            }
        }
    }

    priority_queue<GraphNode*, vector<GraphNode*>, GraphNodeComparator> V(){
        priority_queue<GraphNode*, vector<GraphNode*>, GraphNodeComparator> pq;
        for(auto i = 0; i < nodes.size(); i++)
            pq.push(nodes[i]);
        return pq;
    }

    void printPath(string endNode){
        string temp = "";
        GraphNode* curr = nullptr;
        for(auto n : nodes){
            if(n->getId() == endNode){
                curr = n;
                break;
            }
        }
        while((curr = curr->getPredecessor()) != nullptr){
            temp += curr->getId();
            temp += " ";
        }
        temp += srcNodeId;
        printf("%s\n", temp.c_str());
    }

    ~Graph(){
        for(auto n : nodes){
            delete n;
        }
        nodes.clear();
    }
private:
    int maxsize;
    string srcNodeId;
    vector<GraphNode*> nodes;
};