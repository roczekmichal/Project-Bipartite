#include "libraries.h"

/** \breif check_if_graph_is_bipartite is a function to give a user information if edges he introduced are bipartite graph or not
*
* @param1 std::vector<int> edges - vector with all edges introduced by user
* 
*
* @return - Function returns bool values depending on result of calculation
*/
bool check_if_graph_is_bipartite(std::vector<int> edges)
{

    // In this part programm create a new vector and set to push back edges without repetitions

    std::vector<int> edges_without_repetitions;
    std::set <int> set;


    for (int i : edges)
    {
        if (set.find(i) == set.end())
        {
            set.insert(i);
            edges_without_repetitions.push_back(i);
        }
    }

    //In this part programm colorize values from precvious vector using 0 and 1 

    std::vector<int> colorized_values_of_edges;


    for (int i = 0; i < edges_without_repetitions.size(); i++)
    {
        if (i % 2 == 0)
            colorized_values_of_edges.push_back(0);
        else
            colorized_values_of_edges.push_back(1);
    }


    //In this part programm is colorizing the original edges

    std::vector<int>::iterator it;
    std::vector<int> colorized_edges;


    for (int i = 0; i < edges.size(); i++)
    {
        it = std::find(edges_without_repetitions.begin(), edges_without_repetitions.end(), edges[i]);
        if (it != edges_without_repetitions.end())
           // edges[i] = colorized_values_of_edges[it - edges_without_repetitions.begin()];
            colorized_edges.push_back(colorized_values_of_edges[it - edges_without_repetitions.begin()]);
    }


    // Here is the main part where programm check if graph is bipartite or not and returning true or false

    int n = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        if (i % 2 == 0 && colorized_edges[i] == 0)
            n += 1;
    }


    float size = edges.size();


    if (edges.size() == 2)
    {
        if (colorized_edges[0] == colorized_edges[1])
            return false;
        else
            return true;
    }

    else if (edges.size() % 2 == 0)
    {
        if (n == (size / 2))
            return true;
        else
            return false;
    }

    else
    {
        if (n == ceil((size / 2)))
            return true;
        else
            return false;
    }
}