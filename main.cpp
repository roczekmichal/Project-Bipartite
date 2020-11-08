#include "libraries.h"
#include "function.h"

int main(int argc, char* argv[]) {
        int edge, amount_of_edges;
        std::vector<int> edges;
        std::cout << "Please introduce amount of edges (at least two): " << std::endl;
        std::cin >> amount_of_edges;
        std::cout << "Please introduce your edges: " << std::endl;
        for (int i = 0; i < amount_of_edges; i++)
        {
            std::cin >> edge;
            edges.push_back(edge);
        }
        std::cout << std::endl;

        if (check_if_graph_is_bipartite(edges) == true)
            std::cout << "Graph is bipartite" << std::endl;
        else
            std::cout << "Graph is not bipartite" << std::endl;
      
        return 0;
}