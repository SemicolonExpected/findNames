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

class Edge{
public:
    std::string vertex1;
    std::string vertex2;
    int weight;

    Edge();
    Edge(std::string name1, std::string name2, int new_weight);
    Edge& operator=(Edge rhs);
    bool operator==(const Edge rhs) const {if(vertex1 == rhs.vertex1 && vertex2 == rhs.vertex2 && weight == rhs.weight) 
                                return true; else return false;}
    bool operator<(const Edge rhs) const {if(weight<rhs.weight) return true; else return false;}
};

struct vertex{
    std::string name;
    visited status;
    std::vector<Edge> adjacencies;
    int adjacencies_count;
    /***************************|
    * vertex | vertex | vertex |
    * weight | weight | weight |
    * ************************/
    vertex();
    void add_new_edge(int weight, std::string adjacency);
    int return_adjacency_count();
    void set_status(visited status);
    Edge return_this_edge(std::string name);
    void print_out_adjacencies();
    std::vector<Edge> return_adjacencies();

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
    
    std::vector<Edge> return_these_adjacencies(std::string query);
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
    
    vertices[pos].name = new_vertex;
    //std::cout << "Graph pos " << roots[new_vertex] << " contains " << vertices[pos].name << std::endl;
}

void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name], pos2 = roots[last_name];

    vertices[pos1].add_new_edge(weight, first_name);//Adjacency <first-last>
    vertices[pos2].add_new_edge(weight, last_name);//Adjacency <last-first>

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

std::vector<Edge> Graph::return_these_adjacencies(std::string query)
{
    int pos = roots[query];

    return vertices[pos].return_adjacencies();
}

/*Vertex functions*/

vertex::vertex(){
    status = UNKNOWN;
}
void vertex::add_new_edge(int weight, std::string adjacency)
{
    Edge new_pair(name, adjacency, weight);
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

Edge vertex::return_this_edge(std::string name)
{
    Edge current;
    std::string current_string;
    for(int i = adjacencies.size(); i < adjacencies.size(); i++)
    {
        current = adjacencies[i];

        if( name == current.vertex1 ) return current;
    }
}

void vertex::print_out_adjacencies()
{
    Edge curr;
    for(int i = 0; i < adjacencies.size(); i++)
    {
        curr = adjacencies[i];
        std::cout << curr.vertex1  << "-" << curr.weight << "-" << curr.vertex2 << std::endl;
    }
}

//Will return the vertices' adjacency list.
std::vector<Edge> vertex::return_adjacencies()
{
    std::vector<Edge> edge_triples;

    for(int i = 0; i < adjacencies.size(); i++)
    {
        edge_triples[i].vertex1 = name;
        edge_triples[i].vertex2 = adjacencies[i].vertex2;
        edge_triples[i].weight = adjacencies[i].weight;
    }
    return adjacencies;
}

/******************
 * Edge functions *
 ******************/
 
Edge::Edge(){
    weight = 0;
}
Edge::Edge(std::string name1, std::string name2, int new_weight)
{
    vertex1 = name1;
    vertex2 = name2;
    weight = new_weight;
}

Edge& Edge::operator=(Edge rhs)
{
    if(*this == rhs) return *this;
    else{
        vertex1 = rhs.vertex1;
        vertex2 = rhs.vertex2;
        weight = rhs.weight;
    }
    return *this;
}

bool Edge::operator==(Edge rhs){
    if(vertex1 == rhs.vertex1 && vertex2 == rhs.vertex2 && weight == rhs.weight)
        return true;
    else
        return false;
}

#endif
