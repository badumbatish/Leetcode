class Solution {
    void dfs(std::vector<std::vector<int>> &adj_list, std::set<int>& visited, int source) {
        visited.insert(source);

        for (int i = 0; i < adj_list[source].size(); i++) {
            if (visited.count(adj_list[source][i]) == 0) {
                dfs(adj_list, visited, adj_list[source][i]);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj_list(n);
        std::set<int> visited;
        for(auto& edge : edges) {
            adj_list[edge[1]].push_back(edge[0]);
            adj_list[edge[0]].push_back(edge[1]);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited.count(i) == 0) {
                components++;
                dfs(adj_list, visited, i);
            }
        }

        return components;
    }
};