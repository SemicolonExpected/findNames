#ifndef GRAPH_H
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Vertex.h"

//using namespace std;

class Graph{
private:
    std::map<int, std::string> roots;
    std::vector<vertex> vertices;
public:
    void add_vertex(std::string new_vertex);
    void add_adjacency(std::string first_name, std::string last_name, int weight);
};

#endif
