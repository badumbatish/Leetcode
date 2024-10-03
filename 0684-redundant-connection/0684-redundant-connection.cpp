class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::map<int, std::set<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        for (auto it = edges.rbegin(); it != edges.rend(); it++) {
            auto a = (*it)[0], b = (*it)[1];
            if (graph[a].size() > 1 && graph[b].size() > 1) {
                return *it;
            }
        }

        return {};
    }
};