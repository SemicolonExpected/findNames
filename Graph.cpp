#include <utility>
#include <list>
#include <string>
#include <iostream>

using namespace std;

/*Functions:
	void add_edge(edge) : Adds a new edge to the vertex's adjacency list
	Edge * return_edge_list() : Returns the adjacency list. Used in the graph print_adjacencies(vertex)
	void set_name(string name) : Sets the name of the vertex's value.

*/
class AdjListVertex
{
friend class Edge;

private:
		string name;
		Edge *edges;
		//enum visited;

public:

		AdjListVertex( ) : edge{ nullptr }
		{ }
		string return_name()
		{
			return name;
		}

		void add_edge(Edge * new_edge)//Effectively a linked list of edges for a vertex
		{
			Edge *temp_edge = this;

			while(temp_edge != nullptr)//Much like a linked list, will seek the end of the list...
			{
				temp_edge = temp_edge->edge;
			}

			temp_edge = new_edge;//And add it to the end.
		}

		Edge * return_edge_list()
		{
			return edges;//Returns the linked_list of edges. For figuring out adjacencies.
		}
		void set_name(string name1)
		{
			name = name1;
		}


};

//enum visited = {UNKNOWN, KNOWN, COMPLETE};


/*(If an edge is defined as <vertex_one-vertex_two>, then this is the declaration of the edge.
Functions:
	AdjListVertex * return_first_vertex() //Returns vertex_one
	AdjListVertex * return_second_vertex() //Returns vertex-two
	void set_first_vertex(AdjListVertex *new_vertex() //Does what it do
	void set_second_vertex(AdjListVertex *new_vertex() //^^^^

*/
class Edge
{
private:
		int weight; //Weight. It'll be the Levenshtein distance between one and two.
		AdjListVertex *vertex_one;//Vertex one
		AdjListVertex *vertex_two;//Vertex two
		Edge *next_edge;

public:

	Edge( ) : vertex_one{ nullptr } , vertex_two{nullptr}//Default constructor. Init. vertices to null
	{ }

	AdjListVertex * return_first_vertex()//Return vertex_one
	{
		return vertex_one;
	}

	AdjListVertex * return_second_vertex()//Return vertex_two
	{
		return vertex_two;
	}

	void set_first_vertex(AdjListVertex * new_vertex)//Set the first vertex
	{
		vertex_one = new_vertex;
	}

	void set_second_vertex(AdjListVertex * new_vertex)//Set the second vertex
	{
		vertex_two = new_vertex;
	}




};

//The vertices are stored as a vector of vertices.
//Each vertex has a list of edges, denoting the connections.
//Each edge kindly keeps track of what it's connect via pointers.

/*
Functions:
	void add_vertex( AdjListVertex *new_vertex) adds a vertex, initialized externally
	void add_edge(string name1, string name2, int weight) //If name1 and name2 are in the graph, it will connect them
	void print_adjacencies(string name) //Will print adjacencies of the specified name
*/


class Graph {
friend class Edge;
friend class AdjListVertex;
private:
	vector<AdjListVertex> vertices;

public:

	//Adds a new vertex. Should be done first when connecting a new vertex to an existing vertex!
	void add_vertex(AdjListVertex *new_Vertex) {
		vertices.push_back(new_Vertex);
	}

	//Assuming name1 and name2 are already vertices yet to be connected, it will connect them with the weight provided.
	void add_edge(string name1, string name2, int weight) {

		//These are both very important. This is how we maintain the undirected-ness of the graph
		Edge * temp_edge_1 = new Edge;
		Edge * temp_edge_2 = new Edge;

		int name2_vertex_pos = 0;

		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->return_name() == name1) {
				temp_edge_1->set_first_vertex(vertices[i]);//initializes the two ends of our edges.
				temp_edge_2->set_second_vertex(vertices[i]);

			}
			if(vertices[i]->return_name() == name2)
			{
				name2_vertex_pos = i;//Will remember the position in the vector of our second vertex, name2.
				temp_edge_1->set_second_vertex(vertices[i]);
				temp_edge_2->set_first_vertex(vertices[i]);
			}

			if(temp_edge->return_first_vertex() == nullptr || temp_edge->return_second_vertex() == nullptr) exit(1);

			else if(temp_edge->return_first_vertex() != nullptr && temp_edge->return_second_vertex() != nullptr){

				temp_edge_1->set_weight(weight);
				temp_edge_2->set_weight(weight);

				//This will make sure we add a new edge to both the name1 and name2 vertices.
				vertices[i]->add_edge(temp_edge_1);
				vertices[name2_vertex_pos]->add_edge(temp_edge_2);

			}
		}




	}

	//Still working on it atm...
	void print_adjacencies(string name)
	{
		Edge *edge_list;
		AdjListVertex *current_vertex;
		for(int i = 0; i < vertices.size(); i++)
		{
			if(vertices[i]->return_name() == name)
			{
				edge_list = vertices[i]->return_edge_list();
				break;
			}

		}

		while(edge_list != nullptr)
		{
			AdjListVertex = edge_list->return_second_vertex();

			cout << AdjListVertex->return_name() << endl;
		}
	}

};
