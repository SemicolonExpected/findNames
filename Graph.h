#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include <list>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum visited { UNKNOWN, KNOWN, COMPLETE };

struct vertex{
    std::string name;
    visited status;
    std::vector<std::pair<int, std::string>> adjacencies;
    int adjacencies_count;
    /***************************|
    * vertex | vertex | vertex |
    * weight | weight | weight |
    * ************************/
    vertex();
    void add_new_pair(int weight, std::string adjacency);
    int return_adjacency_count();
    void set_status(visited status);
    std::pair<int, std::string> return_this_pair(std::string name);
    void print_out_adjacencies();

};

class Graph{
private:
    std::map<std::string, int> roots;
    std::vector<vertex> vertices;
public:
    Graph();
    Graph(std::string name);
    void add_vertex(std::string new_vertex);
    void add_adjacency(std::string first_name, std::string last_name, int weight);
    //void dfs(std::string name);
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
    vertices[pos].name = new_vertex;
    std::cout << "Graph pos " << roots[new_vertex] << " contains " << vertices[pos].name << std::endl;
}

void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name], pos2 = roots[last_name];

    vertices[pos1].add_new_pair(weight, first_name);//Adjacency <first-last>
    vertices[pos2].add_new_pair(weight, last_name);//Adjacency <last-first>

}

/*void Graph::dfs(std::string name)
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

}*/

void Graph::print_adjacencies(std::string name)
{
    int pos = roots[name];

    vertices[pos].print_out_adjacencies();
}

/*Vertex functions*/

vertex::vertex(){
    status = UNKNOWN;
}

void vertex::add_new_pair(int weight, std::string adjacency)
{
    std::pair <int, std::string> new_pair(weight, adjacency);
    adjacencies.push_back(new_pair);
    adjacencies_count = adjacencies.size();
}

void vertex::set_status(visited new_state)
{
    status = new_state;
}

int vertex::return_adjacency_count()
{
    return adjacencies_count;
}

std::pair<int, std::string> vertex::return_this_pair(std::string name)
{
    std::pair<int, std::string> current;
    std::string current_string;
    for(int i = adjacencies.size(); i < adjacencies.size(); i++)
    {
        current = adjacencies[i];

        if( name == std::get<1>(current) ) return current;
    }
}

void vertex::print_out_adjacencies()
{
    std::pair<int, std::string> curr;
    for(int i = 0; i < adjacencies.size(); i++)
    {
        curr = adjacencies[i];
        std::cout << name  << "-" << curr.first << curr.second << std::endl;
    }
}

#endif
