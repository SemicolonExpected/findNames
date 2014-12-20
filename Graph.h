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

Graph::Graph()
{

}

Graph::Graph(std::string name)
{
    int pos = vertices.size();
    roots[name]  = pos;

    vertex brand_new;
    brand_new.name = name;

    vertices.push_back(brand_new);
}

void Graph::add_vertex(std::string new_vertex)
{
    int pos = vertices.size();
    roots[new_vertex]  = pos;

    vertex brand_new;
    brand_new.name = new_vertex;

    vertices.push_back(brand_new);
    std::cout << "Graph pos " << roots[new_vertex] << " contains " << vertices[pos].name << std::endl;
}

void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name], pos2 = roots[last_name];

    vertices[pos1].add_new_pair(weight, first_name);//Adjacency <first-last>
    vertices[pos2].add_new_pair(weight, last_name);//Adjacency <last-first>

}

void Graph::dfs(std::string name)
{
    int pos = roots[name];
    pair<int, std::string> curr;
    vertices[pos].set_status(COMPLETE);

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[pos].status == COMPLETE) continue;
        else{
            curr = vertices[pos].return_this_pair(name);
            dfs(std::get<1>(curr));
        }
    }

}

void Graph::print_adjacencies(std::string name)
{
    int pos = roots[name];

    vertices[pos].print_out_adjacencies();
}

#endif
