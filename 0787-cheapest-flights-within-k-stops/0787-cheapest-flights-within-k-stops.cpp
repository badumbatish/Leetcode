class Solution {
    using Dest = int;
    using Cost = int;
    using NumStop = int;

    using Graph = std::vector<std::vector<std::pair<Dest, Cost>>>;
    Graph make_graph(int n, vector<vector<int>>& flight) {
        Graph g = Graph(n);
            for (auto info : flight) {
                g[info[0]].push_back({info[1], info[2]});
            }
        return g;
    }
    
    using Data = std::tuple<Cost, Dest, NumStop>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto graph = make_graph(n, flights);
        std::priority_queue<Data, std::vector<Data>, std::greater<>> pq;

        pq.push({0, src, 0});

        std::vector<int> visited(n, INT_MAX);
        visited[src] = 0;

        while (!pq.empty()) {
            auto [curr_cost, node, num_stop] = pq.top(); pq.pop();

            if (curr_cost > visited[node] || num_stop > k + 1) continue;
            visited[node] = curr_cost;
            if (node == dst) return curr_cost;

            for (auto [neighbor, cost] : graph[node]) {
                pq.push({curr_cost + cost, neighbor, num_stop + 1});
            }
        }

        return -1;
    }
};