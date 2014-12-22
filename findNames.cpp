/***********************
 * Victoria Zhong && Jose Uribe
 * 
 * *********************/
#include "BinaryHeap.h"
#include "Graph.h"

#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>

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

void dothething(Graph agraph, string name, int limit);

Graph prims(Graph& aGraph, BinaryHeap<Edge> &aHeap);

Graph prims(Graph& aGraph, BinaryHeap<Edge> &aHeap){
	
	Edge tempEdge;
	Graph minSpanTree;
	std::vector<Edge> edges;
	
	if(!aHeap.isEmpty()){
		aHeap.deleteMin(tempEdge);
		//start the tree, create the first edge
		minSpanTree.add_vertex(tempEdge.vertex1);
		minSpanTree.add_vertex(tempEdge.vertex2);
		minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);
		
		aGraph.get_this_vertex(tempEdge.vertex1)->ifvisited = true;
		aGraph.incrementVisited();
		aGraph.get_this_vertex(tempEdge.vertex2)->ifvisited = true;
		aGraph.incrementVisited();
		
		
		edges = aGraph.return_these_adjacencies(tempEdge.vertex1);
	    for(int i = 0; i<edges.size(); i++)
	       aHeap.insert(edges[i]); //inserts adjacencies
	    edges = aGraph.return_these_adjacencies(tempEdge.vertex2);
	    
	    for(int i = 0; i<edges.size(); i++)
	       aHeap.insert(edges[i]);
	}
    
    do{
        if(!aHeap.isEmpty()){
            aHeap.deleteMin(tempEdge);
            
            if(aGraph.get_this_vertex(tempEdge.vertex2)->ifvisited = false){ //vertex 2 not visited
                minSpanTree.add_vertex(tempEdge.vertex2);
                aGraph.get_this_vertex(tempEdge.vertex2)->ifvisited = true;
                aGraph.incrementVisited();
                minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);
                
                edges = aGraph.return_these_adjacencies(tempEdge.vertex2);
                for(int i = 0; i<edges.size(); i++)
    	            aHeap.insert(edges[i]);
            }
            else{ //vertex 1 not visited
                minSpanTree.add_vertex(tempEdge.vertex1);
                aGraph.get_this_vertex(tempEdge.vertex1)->ifvisited = true;
                aGraph.incrementVisited();
                minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);
                
                edges = aGraph.return_these_adjacencies(tempEdge.vertex1);
                for(int i = 0; i<edges.size(); i++)
    	            aHeap.insert(edges[i]);
            }
            
        }
        else
            break;
    }
    while(aGraph.getVisited()<2000); //do while not all nodes are visited
    
    return minSpanTree;
	

	
	/************************************
	 * While not all vertices are visited
	 * **********************************/
}

void kruskal(Graph& theGraph, BinaryHeap<Edge> theEdges);

void kruskal(Graph& theGraph, BinaryHeap<Edge> theEdges){
	Edge tempEdge;
	Graph minSpanTree;
	
	while(!theEdges.isEmpty()){ //while the heap is not empty
		//theEdges.deleteMin(tempEdge);
	
		theEdges.deleteMin(tempEdge);
		if(!(theGraph.get_this_vertex(tempEdge.vertex1)->ifvisited == true && 
		theGraph.get_this_vertex(tempEdge.vertex2)->ifvisited == true)) 
		{	//if both arent already connected connect them
			if(theGraph.get_this_vertex(tempEdge.vertex1)->ifvisited == false && 
			theGraph.get_this_vertex(tempEdge.vertex2)->ifvisited == true)
			{
				minSpanTree.add_vertex(tempEdge.vertex1);
				minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);
				theGraph.get_this_vertex(tempEdge.vertex1)->ifvisited = true;
			}
			if(theGraph.get_this_vertex(tempEdge.vertex2)->ifvisited == false && 
				theGraph.get_this_vertex(tempEdge.vertex1)->ifvisited == true)
			{
				minSpanTree.add_vertex(tempEdge.vertex2);
				minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);	
				theGraph.get_this_vertex(tempEdge.vertex2)->ifvisited = true;
			}
			else
			{
				minSpanTree.add_vertex(tempEdge.vertex1);
				minSpanTree.add_vertex(tempEdge.vertex2);
				minSpanTree.add_adjacency(tempEdge.vertex1, tempEdge.vertex2, tempEdge.weight);	
				theGraph.get_this_vertex(tempEdge.vertex1)->ifvisited = true;
				theGraph.get_this_vertex(tempEdge.vertex2)->ifvisited = true;
			}
		
		}
		
			
		//std::cout<<"hello"<<std::endl;
		
	}
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
	 //std::map<string,vertex> graphMap;
	 int numNode = 0;
	 int numEdges = 0;
	 
	 if(!names.eof()){
	 	//adds the first vertex
	 	std::string temporary;
	 	names>>temporary;
	 	theGraph.add_vertex(temporary);
	 	stuff.push_back(temporary);
	 	numNode++;
	 	//std::pair<std::string, int> tempPair(temporary,0);
	 }
	 while(!names.eof())
	 {
	 	string temporary;
	 	names>>temporary; //gets line
	 	theGraph.add_vertex(temporary);
	 	numNode++;
	 	/*************************
	 	 * Check for adjacencies *
	 	 * ********************* */
	 	 
	 	 for(int i = 0; i<stuff.size(); i++){
	 		int weight = edit_distance(temporary, stuff[i]);
	 		if(weight<5){
	 			theGraph.add_adjacency(temporary, stuff[i], weight);
	 			numEdges++;
	 			//theGraph.add_adjacency(stuff[i], temporary, weight);
	 		}
	 	 }
	 	 
	 	 stuff.push_back(temporary);
	 }
	 names.close();
	 
	 std::cout<<"Number of vertices:"<<numNode<<std::endl
	 		  <<"Number of Edges:"<<numEdges<<std::endl;
	 
	 std::vector<Edge> edges;
	 string temporary = stuff.front();  
	 edges = theGraph.return_these_adjacencies(temporary); 
	 BinaryHeap<Edge> theEdges(edges);
	 std::swap(stuff[0],stuff[stuff.size()-1]);
	 stuff.resize(stuff.size()-1);
	 //deletes that element
	 /*while(stuff.size()>0)
	 {
	 	string temporary = stuff.front();
		edges = theGraph.return_these_adjacencies(temporary);
		std::swap(stuff[0],stuff[stuff.size()-1]);
	 	stuff.resize(stuff.size()-1);
	 	
	 	for(int i = 0; i<edges.size(); i++)
	 		theEdges.insert(edges[i]);
	 }*/
	 
	 
	 /***********************************************\
	 	Put things in heap
	 	pop out the minimum
	 	then grab the next minimum that is connected
	 	any node that will get connected is "visited"
	 	if both nodes are "visited" do not add node
	 	thus duplicates or the uv vu is only a waste
	 	of space but will not error.
	 ************************************************/
	
	/********************
	 * Prim's Algorithm *
	 * ******************/
	
	
	Graph minTree = prims(theGraph, theEdges);
	//kruskal(theGraph, theEdges);
	
	/* ************************************ *
	 *           DO THE SEARCH!             *
	 * ************************************ */
	 
	do{
		std::cout<<"Enter a name: (or exit to exit)"<<std::endl;
	    	string name;
	    	std::cin>>name;
    	
	    	if(name == "exit"){
	    	    return 0;
	    	}
	    	
	    	std::cout<<"Enter a depth limit:"<<std::endl;
	    	int limit;
	    	std::cin>>limit;
		minTree.dfs(name, limit, 0);
	}while(name != "exit");
	
	
}

void dothething(Graph agraph, string name, int limit){
    agraph.dfs(name, limit, 0);
}
