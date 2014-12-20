#ifndef GRAPH_H
#define GRAPH_H
#include "Graph.h"
#include "Vertex.h"

void Graph::add_vertex(std::string new_vertex)
{
    int pos = vertices.size();
    roots[new_vertex] = vertices.size();

    vertices[pos].name = new_vertex;

}

void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name], pos2 = roots[last_name];

    vertices[pos1].add_pair(weight, first_name);//Adjacency <first-last>
    vertices[pos2].add_pair(weight, last_name);//Adjacency <last-first>

}

void Graph::dfs(std::string name)
{
    int pos = roots[name];
    pair<int, std::string> curr;
    vertices[pos1].set_status(COMPLETE);

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[pos].vertex[i].visited() == COMPLETE) continue;
        else{
            curr = vertices[pos].return_this_pair(std::string name);
            dfs(std::get<1>(curr));
        }
    }

}


#endif
