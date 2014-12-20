#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>
#include <utility>

enum visited { UNKNOWN, KNOWN, COMPLETE };

struct vertex{
    std::string name;
    visited status;
    std::vector<std::pair<int, std::string>> adjacencies;
    int adjacencies_count;
    /***************************|
    * vertex | vertex | vertex |
    * weight | weight | weight |
    * ************************/
    vertex();
    void add_new_pair(int weight, std::string adjacency);
    int return_adjacency_count();
    void set_status(visited status);
    std::pair<int, std::string> return_this_pair(std::string name);
    void print_out_adjacencies();
    std::vector<std::pair<int, std::string>> return_adjacencies();


};

#endif
