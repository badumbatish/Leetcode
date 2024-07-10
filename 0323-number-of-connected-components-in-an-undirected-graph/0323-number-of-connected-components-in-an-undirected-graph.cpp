class Solution {
public:
void dfs(std::vector<int> adj_list[], std::unordered_set<int> &u_set, int src) {
    u_set.insert(src);

    for (int i = 0; i < adj_list[src].size(); i++)  {
        if (u_set.count(adj_list[src][i]) == 0) {
            dfs(adj_list, u_set, adj_list[src][i]);
        } 
    }
}
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;

        int components = 0;
        std::unordered_set<int> u_set;

        std::vector<int> adj_list[n];

        for (auto &edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (u_set.count(i) == 0) {
                components++;
                dfs(adj_list, u_set, i);
            }
        }

        return components;

    }
};