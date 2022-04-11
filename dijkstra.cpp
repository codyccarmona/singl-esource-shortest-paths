#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[]){
    std::vector<std::string> lines;
    std::string readLine;

    while(std::getline(std::cin, readLine))
        lines.push_back(readLine);

    return 0;
}