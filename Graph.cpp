#include <utility>
#include <string>
using namespace std;

class AdjListVertex
{
private:
		string name;
		vector<Edge> edges;
		enum visited;

public:
		void add_edge(Edge new_edge)
		{
			edges.push_back(new_edge);
		}



};

enum visited = {UNKNOWN, KNOWN, COMPLETE};

class Edge
{
	private:
		pair<string, int> adjacency;

	public:
		Edge( string name, int weight, Edge* next )
			: adj_vertex(vertex), edge_weight(weight) {}

	int adj_vertex() const {return adj_vertex;}

};

class Graph {
private:
	vector <AdjListVertex> vertices;

public:

	void add_node(AdjListVertex new_Vertex) {
		vertices.push_back(new_Vertex);
	}

	void add_edge(string name1, Edge &new_edge) {
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i].name == name1) {
				vertices[i].add_edge(new_edge);
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
