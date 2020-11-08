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

        
        /*
        for (int i = 0; i < argc; i++)                                              //I can't fixed problems with this part of exercise
        {
            if (std::string argv[i] == "-o")
                output_file(edges);

            if (std::string argv[i] == "")
            {
                std::cout << "Short instruction:" << std::endl;
                std::cout << std::endl;
                std::cout << "You have to declare flag:" << std::endl;
                std::cout << "-o to create a text file with result" << std::endl;
            }
        }
        */

        //I've made simply saving result to the file instead of flags

        std::ofstream file;
        file.open("result.txt");

        if (check_if_graph_is_bipartite(edges) == true)
            file << "Graph is bipartite";
        else
            file << "Graph is not bipartite";
        file.close();

        std::cout << "Results are in file results.txt" << std::endl;

   
        return 0;
}