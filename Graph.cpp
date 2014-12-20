#include <utility>
#include <list>
#include <string>
using namespace std;

class AdjListVertex
{
private:
		string name;
		Edge* edge;
		enum visited;

public:

		AdjListVertex( ) : edge{ nullptr }
		{ }
		string return_name()
		{
			return name;
		}

		void add_edge(Edge * new_edge)
		{
			Edge* temp_edge = this;

			while(temp_edge != nullptr)
			{
				temp_edge = temp_edge->edge;
			}
			temp_edge = new_edge;
		}

		void set_name(string name1)
		{
			name = name1;
		}


};

enum visited = {UNKNOWN, KNOWN, COMPLETE};

class Edge
{
private:
		int weight;
		AdjListVertex* vertex_one;
		AdjListVertex* vertex_two;
		Edge* next_edge;

public:

	Edge( ) : vertex_one{ nullptr } , vertex_two{nullptr}
	{ }

	AdjListVertex * return_first_vertex()
	{
		return vertex_one;
	}

	AdjListVertex * return_second_vertex()
	{
		return vertex_two;
	}

	void set_first_vertex(AdjListVertex * new_vertex)
	{
		vertex_one = new_vertex;
	}

	void set_second_vertex(AdjListVertex * new_vertex)
	{
		vertex_two = new_vertex;
	}

	void set_next_edge(Edge * new_edge)
	{
		next_edge = new_edge;
	}


};

class Graph {
private:
	vector<AdjListVertex> vertices;

public:

	void add_node(AdjListVertex new_Vertex) {
		vertices.push_back(new_Vertex);
	}

	void add_edge(string name1, string name2, int weight) {

		Edge * temp_edge_1 = new Edge;
		Edge * temp_edge_2 = new Edge;

		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i]->return_name() == name1) {
				temp_edge->set_first_vertex(vertices[i]);
			}
			if(vertices[i]->return_name() == name2)
			{
				temp_edge->set_second_vertex(vertices[i]);
			}

			if(temp_edge->return_first_vertex() == nullptr || temp_edge->return_second_vertex() == nullptr) exit(1);

			else if(temp_edge->return_first_vertex() != nullptr && temp_edge->return_second_vertex() != nullptr){

				temp_edge->set_weight(weight);

				vertices[i]->add_edge(temp_edge);

			}
		}




	}

	void add_vertex(AdjListVertex &new_vertex)
	{
		vertices.push_back(new_vertex);
	}

	void print_graph_dfs(int current_vertex)
	{
		vertices[current_vertex].set_status(KNOWN)
	}

};
