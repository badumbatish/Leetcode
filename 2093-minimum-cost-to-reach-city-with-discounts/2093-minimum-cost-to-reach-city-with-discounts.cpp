#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        std::vector<std::vector<pair<int, int>>> graph(n);

        for (const auto& highway : highways) {
            int u = highway[0], v = highway[1], toll = highway[2];

            graph[u].emplace_back(v, toll);
            graph[v].emplace_back(u, toll);
        }

        priority_queue<tuple<int, int, int>, std::vector<tuple<int, int, int>>, greater<>> pq;

        pq.emplace(0,0,discounts);

        std::vector<std::vector<int>> visited(n, std::vector<int>(discounts + 1, INT_MAX));

        while (!pq.empty()) {
            auto [current_cost, city, remaining_discounts] = pq.top();

            pq.pop();

            if (city == n - 1) return current_cost;

            for (const auto& [neighbor, toll] : graph[city]) {
                // Without using a discount
                if (current_cost + toll < visited[neighbor][remaining_discounts]) {
                    visited[neighbor][remaining_discounts] = current_cost + toll;
                    pq.emplace(current_cost + toll, neighbor, remaining_discounts);
                }
                // Using a discount (if available) 
                if (remaining_discounts > 0 && current_cost + toll /2 < visited[neighbor][remaining_discounts - 1]) {
                    visited[neighbor][remaining_discounts - 1] = current_cost + toll / 2;
                    pq.emplace(current_cost + toll / 2, neighbor, remaining_discounts - 1);
                }
            }
        }
        return -1;
    }
};
