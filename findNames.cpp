/***********************
 * Victoria Zhong && Jose Uribe
 * 
 * *********************/
#include "BinaryHeap.h"
#include "Graph.h"

#include <vector>
#include <fstream>
#include <string>

template <class T> unsigned int edit_distance(const T& s1, const T& s2)
{
	const size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int> > d(len1 + 1, std::vector<unsigned int>(len2 + 1));
 
	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;
 
	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
            d[i][j] = std::min( std::min(d[i - 1][j] + 1,d[i][j - 1] + 1),
                      d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) );
	return d[len1][len2];
}

void prims(){

}

int main(){
	
	//Graph 
	/********************************************
	 * Takes the name of stuff into the program * 
	 ********************************************/
	 
	 std::ifstream names;
	 names.open("allnames.txt");
	 std::vector<string> stuff;
	 Graph theGraph;
	 //std::vector<std::pair<std::string, int>> vertexes;
	 
	 if(!names.eof()){
	 	//adds the first vertex
	 	std::string temporary;
	 	names>>temporary;
	 	theGraph.add_vertex(temporary);
	 	stuff.push_back(temporary);
	 	//std::pair<std::string, int> tempPair(temporary,0);
	 }
	 while(!names.eof())
	 {
	 	string temporary;
	 	names>>temporary; //gets line
	 	theGraph.add_vertex(temporary);
	 	/*************************
	 	 * Check for adjacencies *
	 	 * ********************* */
	 	 
	 	 for(int i = 0; i<stuff.size(); i++){
	 		int weight = edit_distance(temporary, stuff[i]);
	 		if(weight<4){
	 			theGraph.add_adjacency(temporary, stuff[i], weight);
	 			//theGraph.add_adjacency(stuff[i], temporary, weight);
	 		}
	 	 }
	 	 
	 	 stuff.push_back(temporary);
	 }
	 
	 names.close();
	 
	 std::vector<Edge> edges;
	 string temporary = stuff.front();
	 edges = theGraph.return_these_adjacencies(temporary);
	 BinaryHeap<Edge> theEdges(edges);
	 std::swap(stuff[0],stuff[stuff.size()-1]);
	 stuff.resize(stuff.size()-1);
	 //deletes that element
	 
	 while(stuff.size()>0)
	 {
	 	string temporary = stuff.front();
		edges = theGraph.return_these_adjacencies(temporary);
		std::swap(stuff[0],stuff[stuff.size()-1]);
	 	stuff.resize(stuff.size()-1);
	 	
	 	for(int i = 0; i<edges.size(); i++)
	 		theEdges.insert(edges[i]);
	 }
	 
	 
	 /***********************************************\
	 	Put things in heap
	 	pop out the minimum
	 	then grab the next minimum that is connected
	 	any node that will get connected is "visited"
	 	if both nodes are "visited" do not add node
	 	thus duplicates or the uv vu is only a waste
	 	of space but will not error.
	 ************************************************/
	 
	
}
