/* Notes:
 *Nothing much changed here, except for the add_edge() function.
 *PLEASE KEEP THE ADD_EDGE FUNCTION THE WAY IT IS!
 *
 *DFS Seems to work correctly (IE: It doesn't infinitely recurse and runs to the count entered as the 3rd parameter)
 *Some cleverly place couts will most likely be the end of that problem.
 * 
 *The turn_off_visited() function is not necessary; unless we enter a new name in the enter name do-while loop in main.
 *
 */
/*********************************************************************************************** *
 * Victoria Zhong && Jose Uribe                                                                  *
 *                                                                                               *
 * Last Modified: 22 December 2014 3:40AM                                                        *
 *                                                                                               *
 * Contributions:                                                                                *
 * Victoria Zhong - ideas of implementation                                                      *
 *                - the weird vector pair Depth First Search                                     *
 *                                                                                               *
 * Jose Uribe     - Graph implimentation                                                         *
 *                - Depth First Search                                                           *
 *                                                                                               *
 *                                                                                               * 
 * Citations:                                                                                    *
 * Wikibooks(2014)Levenshtein Distance [Algorithm]. Availible at:                                *
 *  http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B   *
 *                                                                                               *
 * ********************************************************************************************* */

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
    void dfs(std::string name, int limit, int count);
    std::vector<std::pair<std::pair<std::string, int>, int>> dfs(std::string name, int limit, std::vector<std::pair<std::pair<std::string, int>, int>>& nods);
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

//!!!!!!!!!!!!!!!!!!!!!!!!!! DO NOT MESS AROUND WITH THIS. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//IF THERE IS AN ERROR, CHECK THE PARAMETERS TO ADD_NEW_EDGE
void Graph::add_adjacency(std::string first_name, std::string last_name, int weight)
{
    int pos1 = roots[first_name];
    vertices[pos1].add_new_edge(weight, last_name);//Adjacency <last-first> DO NOT ROLL THIS BACK, THIS IS THE CORRECT VERSION.

}

std::vector<std::pair<std::pair<std::string, int>, int>> Graph::dfs(std::string name, int limit, std::vector<std::pair<std::pair<std::string, int>, int>>& nods)
{
    
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
                
                dfs(current_name, --limit, nods);//otherwise, we will go deeper.
            }
        }
    }
    return nods;
}

//DFS IS INCREASINGLY STUPID. YOU ARE WELCOME TO PARSE THIS MESS, THOUGH. PROPERLY PLACED COUT'S ARE ALL THAT IS NEEDED//
void Graph::dfs(std::string name, int limit, int count)
{
	//cout << "Hello!" << "time to depth search to this level: " << limit << endl;
    
        std::cout<<name<< endl;
    int adjacency_size;
    if(limit){

	//cout << "Why hello there, we'll be searching: " << name << endl;
        int pos = roots[name], current_adjacency;
        //pq edges;
        vertices[pos].ifvisited = true;
    
        vertex *this_vertex = get_this_vertex(name);//This vertex. For this instance. Pointers to avoid crazy memory usage
//	cout << "we've grabbed a pointer to the vertex: " << this_vertex->name << endl;
        adjacency_size = this_vertex->adjacencies.size();//The size of the adjacency list. used in the for loop
        std::string current_name;//The current name. used to verify if we should recurse on this name.
    	//cout << "the adjacency size is: " << adjacency_size << endl;
        for(int i = 0; i < adjacency_size; i++){
	    //cout << "Hi again!" << endl;
            current_name = this_vertex->adjacencies[i].vertex2;//Will obtain the name
	  //  cout << "the current name is: " << current_name << endl;
            current_adjacency = roots[current_name];//The position of our potentially unvisited vertex
	    if(vertices[current_adjacency].ifvisited) cout << current_name << " Has already been visited..." << endl;
            if(vertices[current_adjacency].ifvisited) continue;//If the node has already been visited, ignore.
            else if(limit){
		//cout << "I'm in the dfs recurse loop!" << endl;
                for(int j = 0; j<count; j++)
                    std::cout<<"    ";
                    
		vertices[current_adjacency].ifvisited = true;

                
                dfs(current_name, limit-1, count+1);//otherwise, we will go deeper.
            }
        }
    }

    cout << "A recursive call had terminated!" << endl;
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

