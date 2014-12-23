/*			A Couple of notes:
 *1) The file reading was causing the graph to build incorrectly. I have fixed the file reading. Please do not mess
 *   around with the file reading...It works now. If you wanna verify, run it on a small file and read the adjacencies.
 *2)I moved some things around, but it otherwise should work. I messed around with things again in the B-Heap build
 *3) Prim's execution has been moved to the do-while loop that prompts the user to enter a name
 *	It must be here, since the name entered is the starting point for our MST.
 *4) Some levenshtein distances bigger than 4 are getting into the graph. Minor error, but still problematic
 *
 *
 */



/*********************************************************************************************** *
 * Victoria Zhong && Jose Uribe                                                                  *
 *                                                                                               *
 * Last Modified: 22 December 2014 3:40AM                                                        *
 *                                                                                               *
 * Contributions:                                                                                *
 * Victoria Zhong - overloaded operators                                                         *
 *                - Prim's Algorithm                                                             *
 *                - findNames.cpp                                                                *
 *                - the weird vector pair Depth First Search                                     *
 *                                                                                               *
 * Jose Uribe     - Brainstorming Prim's implementation                                          *
 *                                                                                               *
 *                                                                                               * 
 * Citations:                                                                                    *
 * Wikibooks(2014)Levenshtein Distance [Algorithm]. Availible at:                                *
 *  http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B   *
 *                                                                                               *
 * ********************************************************************************************* */
#include "BinaryHeap.h"
#include "Graph.h"

#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <utility>


/************************************************************************************************
 * Wikibooks(2014)Levenshtein Distance [Algorithm]. Availible at:                               *
 *  http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B  *
 ************************************************************************************************/
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

int main(int argc, char *argv[]){
    
    if(argc != 2){
        std::cout<<"Invalid Number of Arguments"<<std::endl;
        return 0;
    }
	
	/********************************************
	 * Takes the name of stuff into the program * 
	 ********************************************/
	 
	 std::ifstream names;
	 names.open(argv[1]);
	 std::vector<string> stuff;
	 Graph theGraph;
	 //std::vector<std::pair<std::string, int>> vertexes;
	 //std::map<string,vertex> graphMap;
	 int numNode = 0;
	 int numEdges = 0;
	 

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
	//!!!!!!!!!!!!!!!!!!DO NOT TOUCH ANYTHING RELATING TO FILE PARSING!!!!!!!!!!!!!!!!!!!!!!!!!!!//
	 string temporary;
	 while(names >> temporary){
	 	//adds the first vertex
	 	theGraph.add_vertex(temporary);
		//cout << "Adding: " << temporary << endl;
	 	stuff.push_back(temporary);
	 	numNode++;
	 	//std::pair<std::string, int> tempPair(temporary,0);
	 }

	 /*cout << "our vector has: " << stuff.size() << " number of items" << endl;

	 for(int i = 0; i < stuff.size(); i++){
		cout << "item: " << i << " in the vector: " << stuff[i] << endl;
	 }*/

	 string temporary2;
	 for(int i = 0; i < stuff.size(); i++)
	 {

		temporary2 = stuff[i];
	 	/*************************
	 	 * Check for adjacencies *
	 	 * ********************* */
	 	 cout << "Checking adjacencies for: " << temporary2 << endl;
	 	 for(int j = 0; j<stuff.size(); j++){
	 		int weight = edit_distance(temporary2, stuff[j]);
	 		if(weight<=4 && stuff[i] != stuff[j]){
				//cout << temporary2 << " is adjacent to: " << stuff[j] << endl;
	 			theGraph.add_adjacency(temporary2, stuff[j], weight);
	 			numEdges++;
	 			//theGraph.add_adjacency(stuff[i], temporary, weight);
	 		}
	 	 }
	 	 
	 	 //stuff.push_back(temporary);
	 }

         //theGraph.print_adjacencies("Sophia");
	//return 0;
	 names.close();
	 
	 std::cout<<"Number of vertices:"<<numNode<<std::endl
	 		  <<"Number of Edges:"<<numEdges<<std::endl;
	 
	 
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
	
	
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!! PRIM'S CALL HAS BEEN MOVED INTO THE FINAL DO WHILE LOOP BELOW VVVVVVVVVVVVVVVV
	//kruskal(theGraph, theEdges);
	
	/* ************************************ *
	 *           DO THE SEARCH!             *
	 * ************************************ */
	 
        string name;
	int limit;
	do{
		std::cout<<"Enter a name: (or exit to exit)"<<std::endl;

	    	std::cin>>name;
    	
	    	if(name == "exit"){
	    	    return 0;
	    	}

		cout << "adjacencies: " << endl;
		theGraph.print_adjacencies(name);
		int numby;
		cout << "enter a depth!" << endl;
		cin >> numby;


		theGraph.dfs(name, numby, 0);

		return 0;

		//!!!!!!!!!!!!!!!!!!!!!! PRIM'S CALL SHOULD BE HERE, USING THE NAME THAT THE USER INPUT!!!!!!!!!!!!!!!!!!!//
	    	std::vector<Edge> edges	;
	 	edges = theGraph.return_these_adjacencies(name); 
		//theGraph.print_adjacencies(name);
	 	BinaryHeap<Edge> theEdges(edges);
	 	std::swap(stuff[0],stuff[stuff.size()-1]);
	 	stuff.resize(stuff.size()-1);
		Graph minTree = prims(theGraph, theEdges);
		minTree.print_adjacencies(name);
	    	std::cout<<"Enter a depth limit:"<<std::endl;

	    	std::cin>>limit;
		cout << "Your limit will be: "<< limit << endl;

		
		//minTree.dfs(name, limit, 0);
	}while(name != "exit");
	
	
}

void dothething(Graph agraph, string name, int limit){
    agraph.dfs(name, limit, 0);
}

