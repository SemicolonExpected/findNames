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

#endif
