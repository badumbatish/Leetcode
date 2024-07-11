class Solution {
    int ans= 0 ;
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        std::unordered_map<int, std::vector<int>> adj_list;

        for (auto &edge : corridors) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        for (auto &i : adj_list) {
            dfs(adj_list, i.first, i.first, 0);
        }

        return ans;
    }

    void dfs(std::unordered_map<int, std::vector<int>> &adj_list, int current, int start, int length) {
        for (int &neighbor : adj_list[current]) {
            if (length == 2 && neighbor == start) {
                ans++;
            } else if (length < 2 && neighbor > current) dfs(adj_list, neighbor, start, length + 1);
        }
    }
};