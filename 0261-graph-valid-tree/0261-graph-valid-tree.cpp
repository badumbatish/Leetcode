class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj_list(n);

        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        std::stack<int> stck;
        stck.push(0);

        std::map<int, int> parent;
        parent[0] = -1;

        while (!stck.empty()) {
            int node = stck.top(); stck.pop();

            for (auto neighbor : adj_list[node]) {
                if (parent[node] == neighbor) continue;
                if (parent.count(neighbor)) return false;

                stck.push(neighbor);
                parent[neighbor] = node;
            }
        }

        return parent.size() == n;
    }
};