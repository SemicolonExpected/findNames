#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "BinaryHeap.h"
#include <string>
#include "Graph.h"

using namespace std;/***********************
                    * Victoria Zhong, Jose Uribe
                    *
                    * *********************/

void fileCheck(ifstream& file); //checks if the file has been opened succesfully

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

int main(){

    //Graph
    /********************************************
    * Takes the name of stuff into the program *
    ********************************************/

    std::ifstream names("allnames.txt");
    fileCheck(names);
    std::vector<string> stuff;
    Graph theGraph;
    //std::vector<std::pair<std::string, int>> vertexes;

    string temporary1;

    cout << "loop tiem" << endl;
    while(names >> temporary1){
        //adds the first vertex
        cout << "You're adding name: " << temporary1 << endl; //A checker. Remove if you want less cout clutter

        theGraph.add_vertex(temporary1);
        stuff.push_back(temporary1);
        //std::pair<std::string, int> tempPair(temporary,0);
    }
    string temporary2;
    for(int i = 0; i < stuff.size(); i++)
    {
        temporary2 = stuff[i];
        /*************************
        * Check for adjacencies *
        * ********************* */
        cout << temporary2 << endl;//Checking to see if temporary2 got passed successfully. Removal is OK.
        for(int j = i+1; j < stuff.size(); j++){//Will check to see if adjacencies may be added.
            int weight = edit_distance(temporary2, stuff[j]);
            if(weight<4){
                cout << "Adjacency added" << endl;//Checker
                cout << "For: " << temporary2 << " " << stuff[j] << " " << "weight: " << weight << endl;//Checker
                theGraph.add_adjacency(temporary2, stuff[j],weight);
            }
        }

    }

    //Some random checking
    cout << "Adjacencies for Sophia: " << endl;
    theGraph.print_adjacencies("Sophia");
    cout << "Adjacencies for Sophie" << endl;
    theGraph.print_adjacencies("Sophie");

    return 0;
}

void fileCheck(ifstream& file)
//simply put, this function will check if the file is within the same directory as the executable.
//Otherwise, the program will end, prompting the changing of location of the file.
{
    if(file.fail())
    {
        cerr << "Input file could not be opened. Check if the file is in the same directory"
                << " as the executable.\n";
        exit(1);
    }
}
