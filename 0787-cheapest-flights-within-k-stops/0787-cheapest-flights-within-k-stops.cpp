class Solution {
    using Graph = std::map<int, std::vector<std::pair<int, int>>>;

    Graph make_graph(int n, vector<vector<int>>& flight) {
        Graph g;
        for (auto &v: flight) {
            auto a = v[0], b = v[1], c = v[2];
            g[b].push_back({a, c});
        }

        return g;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto graph = make_graph(n, flights);
        std::vector<std::vector<int>> dist(k+2, std::vector<int>(n, INT_MAX /2));
        dist[0][src] = 0;

        for (int i = 1; i <= k + 1; i++){
            for (auto [node, neighbors] : graph) 
                for (auto [neighbor, weight] : neighbors) 
                    dist[i][node] = std::min({dist[i][node], dist[i-1][node], dist[i-1][neighbor] + weight});
        }
        return dist[k + 1][dst] == INT_MAX / 2 ? -1 : dist[k+1][dst]; 
    }
};