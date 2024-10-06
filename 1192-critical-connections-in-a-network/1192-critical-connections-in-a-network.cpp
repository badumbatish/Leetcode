class Solution {
public:
    using Graph = std::vector<std::vector<int>>;

    Graph make_graph(int n, std::vector<std::vector<int>>& connections) {
        // Step 1: Build the graph as an adjacency list
        vector<vector<int>> graph(n);
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        return graph;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        auto graph = make_graph(n, connections); 
        std::vector<int> disc(n, 0), low(n, 0); // discovery time of each node (0 means unvisited)
        std::vector<std::vector<int>> bridges; // store critical connections
        int time = 1; // discovery time counter
        
        // Step 3: DFS function to find critical connections (bridges)
        function<void(int, int)> dfs = [&](int node, int parent) {
            disc[node] = low[node] = time++;
            
            for (int neighbor : graph[node]) {
                if (neighbor == parent) continue;
                
                // If not discovered yet
                if (!disc[neighbor]) {
                    dfs(neighbor, node);
                    
                    low[node] = min(low[node], low[neighbor]);
                    
                    if (low[neighbor] > disc[node]) 
                        bridges.push_back({node, neighbor});
                    
                } 
                else low[node] = min(low[node], disc[neighbor]);
            }
        };
        
        // Step 4: Perform DFS from any node (start with node 0)
        dfs(0, -1);
        
        return bridges;
    }
};
