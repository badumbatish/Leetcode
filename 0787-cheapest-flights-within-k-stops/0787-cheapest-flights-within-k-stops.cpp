class Solution {


    using Cost = int;
    using Dest = int;
    using NumStop = int;
    using Data = std::tuple<int, int, int>;
    using Graph = std::vector<std::vector<std::tuple<Dest, Cost>>>;
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
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto graph = make_graph(n, flights);
        std::priority_queue<Data, std::vector<Data>, greater<>> pq;

        pq.push({0, src, 0});

        std::vector<int> visited(n,  INT_MAX); 
        while (!pq.empty()) {
            auto [current_cost, node, num_stops] = pq.top(); pq.pop();

            if (num_stops > visited[node] || num_stops > k + 1) continue;

            visited[node] = num_stops;

            if (node == dst) return current_cost;
            if (num_stops > k) continue;
            for (auto [neighbor, flight_cost] : graph[node]) {
                pq.push({current_cost + flight_cost, neighbor, num_stops + 1});
            }
        }

        return -1;
    }
};