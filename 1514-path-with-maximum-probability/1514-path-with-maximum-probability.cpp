class Solution {

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        std::unordered_map<int, std::set<std::pair<int, double>>> adj_list;
        for (int i = 0; i < edges.size(); i++) {
            auto node_a = edges[i][0], node_b = edges[i][1];
            adj_list[node_a].insert({node_b, succProb[i]});
            adj_list[node_b].insert({node_a, succProb[i]});
        }
    
        std::map<int, double> dist_map;
        std::priority_queue<std::pair<double, int>> q;
        q.push({1.0, start_node});
        dist_map[start_node] = 1.0;

        while (!q.empty()) {
        
            auto [dist, from] = q.top(); q.pop();
            for (auto &[to, dist_from_to] : adj_list[from]) {
                auto connected_dist = dist * dist_from_to;
                if (!dist_map.contains(to) || connected_dist > dist_map[to]) {
                    q.push({connected_dist, to});
                    dist_map[to] = connected_dist;
                }
            }
        }

        if (!dist_map.contains(end_node)) return 0.0;
        else return dist_map[end_node];
    }
};