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
        // Make a graph adj list
        Graph graph = make_graph(flights);

        // BFS

        // Have a priority queue orignally src 
        // Tuple of 3: cost, node, level 
        using Data = std::tuple<int, int>;
        std::queue<Data> pq; 
        std::vector<int> visited(n, INT_MAX);
        pq.push({0, src});
        visited[src]= 0;
        int stops = 0 ;
        // Go until we found dst 
        while (stops <= k  && !pq.empty()) {
            int sz = pq.size();
            while (sz--) {
                auto [price, node] = pq.front(); pq.pop();
                for (auto [to, distance] : graph[node] ) {
                    if (price + distance >= visited[to]) continue;
                    visited[to] = price+ distance;
                    pq.push({visited[to], to});
                }
            }
            stops++;
        }
        // return cheapest

        return visited[dst] != INT_MAX ? visited[dst] : -1;
    }
};