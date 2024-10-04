class Solution {
public:
    // Find function for Union-Find (with path compression)
    int find(int u, vector<int>& parent) {
        // if u is not its own root, we need to find parent[u]'s root
        if (u != parent[u]) {
            parent[u] = find(parent[u], parent);  // Path compression
        }
        return parent[u];
    }
    
    // Union function for Union-Find (with union by rank)
    bool unite(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = find(u, parent);
        int rootV = find(v, parent);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
                rank[rootU]++;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                rank[rootV]++;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Sort connections by cost
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        // Initialize Union-Find
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        
        int totalCost = 0;
        int edgesUsed = 0;
        
        // Process each connection
        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            int cost = conn[2];
            
            // If the cities are not connected, connect them
            if (unite(u, v, parent, rank)) {
                totalCost += cost;
                edgesUsed++;
                
                // If we have used n - 1 edges, the MST is complete
                if (edgesUsed == n - 1) {
                    return totalCost;
                }
            }
        }
        
        // If we used less than n - 1 edges, it's impossible to connect all cities
        return -1;
    }
};
