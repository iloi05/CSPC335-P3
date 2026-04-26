/*
Names: Ivy Loi, Homan Qiu, Richie Nguyen, Robert Gutierrez
Emails: ioloi05@csu.fullerton.edu, hqiu2006@csu.fullerton.edu, richienguyen@csu.fullerton.edu, lil.rjg3@csu.fullerton.edu
CPSC 335 section 11
Project 3: Algorithm 1
Date: 4/24/2026
*/

#include <iostream>
#include <vector>
#include <algorithm>

int cheapestRoute(std::vector<std::vector<int>>& routes,
                    int src, 
                    int dst,
                    int k ) 
{
        // Uses Bellman-Ford because it naturally limits the number of edges by running k + 1 times

        // Used to represent nodes that aren't reachable yet
        const int INFINITY = 1000000000; // large number to represent infinity


        // Finds number of nodes
        int n = std::max(src, dst); // Max nodes have to be the largest int in src/dst

        for (const auto& r : routes) {
            n = std::max(n, std::max(r[0], r[1]));
        }
        n += 1;

        // Initializes cost array
        std::vector<int> cost(n, INFINITY);
        cost[src] = 0;

        // Bellman-ford algorithm
        for (int i = 0; i <= k; ++i) {
            std::vector<int> tempCost = cost;

            for (const auto& route: routes) {
                int from = route[0];
                int to = route[1];
                int price = route[2];

                // Checks if path exists and compares new cost vs current best cost
                if (cost[from] != INFINITY &&
                    cost[from] + price < tempCost[to]) {
                        tempCost[to] = cost[from] + price;
                }
            }

            cost = tempCost;
        }

    // returns result from cost array
    if (cost[dst] == INFINITY)
        return -1;
    else
        return cost[dst];
}


int main() {
    std::vector<std::vector<int>> route = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    std::cout << "Sample 1: " << cheapestRoute(route, 0, 2, 1) << std::endl;
    std:: cout << "Expected: 200" << std::endl;

    std::cout << "Sample 2: " << cheapestRoute(route, 0, 2, 0) << std::endl;
    std:: cout << "Expected: 500" << std::endl;


    std::cout << "Sample 3: " << cheapestRoute(route, 0, 3, 1) << std::endl;
    std:: cout << "Expected: -1" << std::endl;

    
    return 0;
}