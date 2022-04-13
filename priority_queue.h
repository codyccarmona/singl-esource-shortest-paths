#include <vector>
#include <string>
#include <map>
#include "string_c.h"
using namespace std;

struct Vertex{
    Vertex(string i = "", double e = __FLT_MAX__) : estimate(e), predecessor(nullptr), id(i) { }

    void setEstimate(double d){
        estimate = d;
    }

    double estimate;
    Vertex* predecessor;
    std::string id;
    string adjacencies;
};

struct VertexComparator{
    bool operator()(const Vertex& x, const Vertex& y){
        return x.estimate > y.estimate;
    }
};

struct Edge{
    Vertex* start, end;
    double weight;
};

struct Graph{
    Graph(){}
    Graph(vector<pair<string, string>> vertexLabels, string startVertexLabel) {
        for(auto index = 0; index < vertexLabels.size(); index++){
            Vertex temp = (vertexLabels[index].first == startVertexLabel) ? Vertex(vertexLabels[index].first, 0.0) : Vertex(vertexLabels[index].first); 
            temp.adjacencies = trim(vertexLabels[index].second);
            V.push_back(temp);
        }
    }
private:
    std::vector<Vertex> V;
    
};

