#ifndef GRAPH_H
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "Vertex.h"

using namespace std;

class Graph{
private:
    std::map<std::string, int> roots;
    std::vector<vertex> vertices;
public:
    Graph();
    Graph(std::string name);
    void add_vertex(std::string new_vertex);
    void add_adjacency(std::string first_name, std::string last_name, int weight);
    void dfs(std::string name);
    void print_adjacencies(std::string);
};

#endif
