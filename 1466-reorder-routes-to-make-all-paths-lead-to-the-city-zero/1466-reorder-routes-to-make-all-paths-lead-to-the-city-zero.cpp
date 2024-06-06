class Solution {
private:
    int n;
    std::vector<std::vector<std::pair<int, int>>> adj;

    int count = 0;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        this->n = n;
        adj = std::vector<std::vector<std::pair<int, int>>>(n);
        for (auto &connection : connections) {
            
            // from connnections, we know that con[0] -> con[1] is there.
            // so we need to add con[0] <- con[1]
            adj[connection[0]].push_back({connection[1], 1}); // this is from con[0] pov
            adj[connection[1]].push_back({connection[0], 0}); // this is from con[1] pov

        }

        dfs(0, -1);

        return count;
    }

    void dfs(int node, int parent) {
        for (auto &[neighbor, sign] : adj[node]) {
            // since we know that it is a tree, we would be re-visiting if the neighbor is the parent
            if (neighbor == parent) continue;

            count += sign;
            dfs(neighbor, node);
        }
    }
};