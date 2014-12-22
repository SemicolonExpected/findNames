    ////// ////// ////// ////// ////// 
    //  // //     //       //     //
    ////// ////// //       //     //
    //  //     // //       //     //
    //  // ////// ////// ////// //////

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
 *                - Graph implimentation                                                         *
 *                - Depth First Search                                                           *
 *                                                                                               *
 *                                                                                               * 
 * Citations:                                                                                    *
 * Wikibooks(2014)Levenshtein Distance [Algorithm]. Availible at:                                *
 *  http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C.2B.2B   *
 *                                                                                               *
 * ********************************************************************************************* */

g++ -std=c++0x findNames.cpp -o findNames
./findNames filename

This program takes all the names and adds them to an adjacency list. Then all the edges are found
and added into a heap. In Kruskals, the algorithm creates a new graph and pops out edges and adds
those vertexes and adjacencies as long as it hasnt been added before. In Prims, it acts as a 
pops out the first member of the heap and has a separate heap listing all the adjacencies and 
weights of added vertices.

We contemplated adding uv and vu as separate edges due to this being undirected, but for the 
implimentation of both Kruskals, Prims, and DFS, uv already imples vu.
