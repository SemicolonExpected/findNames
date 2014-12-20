#ifndef VERTEX_H
#define VERTEX_H

vertex::vertex(){
    visited = UNKNOWN;
}
void vertex::add_new_pair(int weight, std::string adjacency)
{
    pair <int, std::string> new_pair(weight, adjacency);
    adjacencies.push_back(new_pair);
    adjacencies_count = adjacencies.size();
}

void vertex::set_status(visited new_state)
{
    visited = new_state;
}

int vertex::return_adjacency_count()
{
    return adjacencies_count;
}

pair<int, std::string> vertex::return_this_pair(std::string name)
{
    pair<int, std::string> current;
    string current_string;
    for(int i = adjacencies.size(); i < adjacencies.size(); i++)
    {
        current = adjacencecies[i]

        if(name == std::get<1>(current) ) return current;
    }
}

#endif
