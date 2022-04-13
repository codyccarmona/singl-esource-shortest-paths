#include <fstream>

#include <bits/stdc++.h>
#include "priority_queue.h"
using namespace std;

void dijkstra(Graph& g){

}

int main(int argc, char *argv[]){
    ifstream file(argv[1]);
    Graph G;
    vector<pair<string, string>> lines;
    string vertexCount;
    
    getline(file, vertexCount);
    lines = vector<pair<string, string>>(stoi(vertexCount));

    for(int i = 0; i < stoi(vertexCount); i++){
        getline(file, lines[i].first, ' ');
        getline(file, lines[i].second);
    }

    file.close();

    G = Graph(lines, argv[2]);    
    return 0;
}