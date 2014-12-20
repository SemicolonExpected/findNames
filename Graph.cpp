#include "Graph.h"
#include "Vertex.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

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
