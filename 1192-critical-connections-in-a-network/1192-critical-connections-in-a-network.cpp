class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Step 1: Build the graph as an adjacency list
        vector<vector<int>> graph(n);
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        // Step 2: Initialize variables
        vector<int> disc(n, -1); // discovery time of each node (-1 means unvisited)
        vector<int> low(n, -1);  // lowest discovery time reachable from the node
        vector<vector<int>> bridges; // store critical connections
        int time = 0; // discovery time counter
        
        // Step 3: DFS function to find critical connections (bridges)
        function<void(int, int)> dfs = [&](int node, int parent) {
            disc[node] = low[node] = time++;
            
            for (int neighbor : graph[node]) {
                if (neighbor == parent) {
                    // Don't go back to the parent
                    continue;
                }
                
                if (disc[neighbor] == -1) {
                    // If the neighbor is not visited, visit it
                    dfs(neighbor, node);
                    
                    // Check if the current node has a back edge
                    low[node] = min(low[node], low[neighbor]);
                    
                    // If the lowest time of the neighbor is greater than the discovery time of the current node
                    if (low[neighbor] > disc[node]) {
                        bridges.push_back({node, neighbor});
                    }
                } else {
                    // If the neighbor is already visited, update the low value
                    low[node] = min(low[node], disc[neighbor]);
                }
            }
        };
        
        // Step 4: Perform DFS from any node (start with node 0)
        dfs(0, -1);
        
        return bridges;
    }
};
