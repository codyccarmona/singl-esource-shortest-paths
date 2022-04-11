#include <vector>
#include <string>
#include <iostream>
#include <fstream>

struct Vertex{
    Vertex() : d(__DBL_MAX__), pi(nullptr) {}
    
    void setd(double d){ this->d = d; }
private:
    double d;
    Vertex* pi;
};

struct Graph{
    Graph(){}
    Graph(int size) : vertices(std::vector<Vertex>(size, Vertex())) {}
private:
    std::vector<Vertex> vertices;
};

std::vector<std::string> readLines(std::string file){
    std::ifstream srcFile(file);
    std::string readLine;
    std::vector<std::string> lines;

    while(std::getline(srcFile, readLine))
        lines.push_back(readLine);

    srcFile.close();

    return lines;
}

int main(int argc, char *argv[]){
    std::vector<std::string> lines = readLines(argv[1]);

    return 0;
}