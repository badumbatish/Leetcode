class Solution {
    std::vector<int> visited;
    int n;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        visited = std::vector<int>(n, 0);

        //for (int i = 0; i < n; i++) dfs(i, graph);

        std::vector<int> safe_nodes;
        for (int i = 0; i < n; i++) {
            if (!dfs(i, graph)) safe_nodes.push_back(i);
        }

        return safe_nodes;
    }


    // True means i have a cycle
    // False means i dont have a cycle
    bool dfs(int node, std::vector<std::vector<int>>& graph) {
        if (visited[node] == 1) return true;

        if (visited[node] == 2) return false;

        visited[node] = 1;
        for (auto neighbor: graph[node]) {
            if (dfs(neighbor, graph)) return true;
        }
        visited[node] = 2;
        return false;
    }
};