class Solution {
    using Graph = std::vector<std::vector<std::tuple<int, int>>>;
    // 0 -> [....]  
    // 1 -> [...........]  
    // 2 -> [..]

    Graph make_graph(int n, vector<vector<int>>& flights) {
        Graph graph(n);

        for (auto flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        return graph;
    }
    

    // Current cost of flight - desitination - # of stops
    using Data = std::tuple<int, int, int>;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> bellman(n, INT_MAX);
        bellman[src]  = 0;
        auto temp = bellman;
        for (int i = 0; i <= k; i++) {
            std::cout << "k is " << i << std::endl;
            for (auto flight : flights) {
                if (bellman[flight[0]] == INT_MAX) continue;
                temp[flight[1]] = std::min(temp[flight[1]], bellman[flight[0]] + flight[2]);
                std::cout << flight[1] << " " << temp[flight[1]] << std::endl;
            }
            std::swap(bellman, temp);
        }
        if (bellman[dst] == INT_MAX ){
            return -1;
        } 
        return bellman[dst];
    }
};