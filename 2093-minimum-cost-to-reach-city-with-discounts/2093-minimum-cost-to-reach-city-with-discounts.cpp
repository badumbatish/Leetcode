#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& highway : highways) {
            int u = highway[0], v = highway[1], toll = highway[2];
            graph[u].emplace_back(v, toll);
            graph[v].emplace_back(u, toll);
        }

        // Priority queue for Dijkstra's algorithm: (cost, city, remaining discounts)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, discounts); // Start from city 0 with 0 cost and all discounts available
        
        // Visited array to track minimum cost at each city with a given number of discounts remaining
        vector<vector<int>> visited(n, vector<int>(discounts + 1, INT_MAX));
        visited[0][discounts] = 0; // Starting city has 0 cost with all discounts

        while (!pq.empty()) {
            auto [current_cost, city, remaining_discounts] = pq.top();
            pq.pop();
            
            // If we reached the last city, return the current cost
            if (city == n - 1) {
                return current_cost;
            }
            
            // For each neighbor, try both without discount and with discount
            for (const auto& [neighbor, toll] : graph[city]) {
                // Without using a discount
                if (current_cost + toll < visited[neighbor][remaining_discounts]) {
                    visited[neighbor][remaining_discounts] = current_cost + toll;
                    pq.emplace(current_cost + toll, neighbor, remaining_discounts);
                }

                // Using a discount (if available)
                if (remaining_discounts > 0 && current_cost + toll / 2 < visited[neighbor][remaining_discounts - 1]) {
                    visited[neighbor][remaining_discounts - 1] = current_cost + toll / 2;
                    pq.emplace(current_cost + toll / 2, neighbor, remaining_discounts - 1);
                }
            }
        }

        // If we never reached the last city, return -1
        return -1;
    }
};
