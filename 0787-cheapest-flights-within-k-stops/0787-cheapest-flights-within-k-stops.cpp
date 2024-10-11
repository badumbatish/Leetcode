class Solution {
public:
    using Graph = std::unordered_map<int, std::vector<std::pair<int, int>>>;

    Graph make_graph(vector<vector<int>>& flights)  {
        Graph graph;
        for (auto &flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        return graph;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dist(n, std::numeric_limits<int>::max() / 2);

        dist[src] = 0;

        std::vector<int> temp(dist);
        for (int i = 0; i <= k; i++) {
            for (auto &flight : flights) {
                temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
            }
            std::swap(dist,temp);
        }
        return dist[dst] == numeric_limits<int>::max() / 2 ? -1 : dist[dst];
    }
};