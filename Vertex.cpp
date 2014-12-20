#include "Vertex.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>

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
