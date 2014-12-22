#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include <list>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct Edge{
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
    std::vector<Edge> adjacencies;
    int adjacencies_count;
    /***************************|
    * vertex | vertex | vertex |
    * weight | weight | weight |
    * ************************/
    vertex();
    void add_new_edge(int weight, std::string adjacency);
    int return_adjacency_count();
    
    //void set_status(visited status);

    Edge return_this_edge(std::string name);
    void print_out_adjacencies();
    std::vector<Edge> return_adjacencies();

    bool ifvisited;
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
    std::vector<std::pair<std::pair<std::string, int>, int>> dfs(std::string name, int limit);
    void print_adjacencies(std::string);
    
    std::vector<Edge> return_these_adjacencies(std::string query);
    vertex* get_this_vertex(const std::string query);
    
    int getVisited(){return numVisited;}
    int numVisited;
    
    void incrementVisited(){numVisited++;}
};

Graph::Graph()
{
    numVisited = 0;
}

Graph::Graph(std::string name)
{
    int pos = vertices.size();
    roots[name]  = pos;

    vertex brand_new;
    brand_new.name = name;

    vertices.push_back(brand_new);
    
    numVisited = 0;
}

void Graph::add_vertex(std::string new_vertex)
{
    int pos = vertices.size();
    roots[new_vertex]  = pos;
    
    vertex brand_new;
    brand_new.name = new_vertex;
    vertices.push_back(brand_new);
    
    vertices[pos].name = new_vertex;
    
    //numVisited++;
    //std::cout << "Graph pos " << roots[new_vertex] << " contains " << vertices[pos].name << std::endl;
}

void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name], pos2 = roots[last_name];

    //vertices[pos1].add_new_edge(weight, first_name);//Adjacency <first-last>
    vertices[pos2].add_new_edge(weight, last_name);//Adjacency <last-first>

}

std::vector<std::pair<std::pair<std::string, int>, int>> Graph::dfs(std::string name, int limit)
{
    std::vector<std::pair<std::pair<std::string, int>, int>> nods;
    
    if(limit > 0){
        int pos = roots[name], current_adjacency;
        //pq edges;
        vertices[pos].ifvisited = true;
    
        vertex *this_vertex = get_this_vertex(name);//This vertex. For this instance. Pointers to avoid crazy memory usage
        int adjacency_size = this_vertex->adjacencies.size();//The size of the adjacency list. used in the for loop
        std::string current_name;//The current name. used to verify if we should recurse on this name.
    
        for(int i = 0; i < adjacency_size; i++){
            current_name = this_vertex->adjacencies[i].vertex2;//Will obtain the name
            current_adjacency = roots[current_name];//The position of our potentially unvisited vertex
            if(vertices[current_adjacency].ifvisited) continue;//If the node has already been visited, ignore.
            else{
                std::pair<std::string, int> temp;
                std::pair<std::pair<std::string, int>,int> temp2;
                temp =std::make_pair(name, this_vertex->adjacencies[i].weight);
                temp2 = std::make_pair(temp, limit);
                nods.push_back(temp2);
                
                dfs(current_name, --limit);//otherwise, we will go deeper.
            }
        }
    }
    return nods;
}

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

vertex* Graph::get_this_vertex(const std::string query)
{
    int pos = roots[query];

    return &vertices[pos];
}


/*Vertex functions*/

vertex::vertex(){
    ifvisited = false;
}



void vertex::add_new_edge(int weight, std::string adjacency)
{
    Edge new_pair(name, adjacency, weight);
    adjacencies.push_back(new_pair);
    adjacencies_count = adjacencies.size();
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


#endif
