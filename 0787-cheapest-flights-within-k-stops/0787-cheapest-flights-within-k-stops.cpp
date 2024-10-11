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
        std::vector<std::vector<int>> cheapest(k, std::vector<int>(n, INT_MAX));
        std::cout << "hi there" << std::endl;
        cheapest[0][src] = 0;
        // Have a priority queue orignally src 
        // Tuple of 3: cost, node, level 
        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < n; j++) {
                for (auto [neighbor, cost] : graph[j]) {
                    std::cout << "hi" << std::endl;
                    //cheapest[i+1][neighbor] = min(cheapest[i][neighbor], cheapest[i][j] + cost);
                }
            }
        }

        return cheapest[k-1][dst];
    }
};