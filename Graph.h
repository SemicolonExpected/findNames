#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include <list>
#include <string>
#include <iostream>

using namespace std;

struct vertex{
    string astring;
    vector<vector<vertex,int>> node; 
    /***************************|
     * vertex | vertex | vertex |
     * weight | weight | weight |
     * ************************/
};

struct graph{
    vector<vector<int,vertex>> nodes; //just add pairs of vertexes and its weight connecting to another vertex
};

#endif
