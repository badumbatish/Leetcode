class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        for (auto highway : highways) {
            auto a = highway[0], b = highway[1], toll = highway[2];
            graph[a].emplace_back(b, toll);
            graph[b].emplace_back(a, toll);


        }

        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, greater<>> pq;;

        std::vector<std::vector<int>> visited (n, std::vector<int>(discounts + 1, INT_MAX));
        pq.emplace(0, 0, discounts);

        while (!pq.empty()) {
            auto [current_cost, city, remaining_discounts] = pq.top(); pq.pop();

            if (city == n - 1) return current_cost;

            for (const auto& [neighbor, toll] : graph[city]) {
                if (current_cost + toll < visited[neighbor][remaining_discounts]) {
                    visited[neighbor][remaining_discounts] = current_cost + toll;
                    pq.emplace(current_cost + toll, neighbor, remaining_discounts);
                }

                if (remaining_discounts > 0 && current_cost + toll /2 < visited[neighbor][remaining_discounts - 1]) {
                    visited[neighbor][remaining_discounts - 1] = current_cost + toll / 2;

                    pq.emplace(current_cost + toll / 2, neighbor, remaining_discounts- 1);
                }
            }
        } 

        return -1;
    }
};