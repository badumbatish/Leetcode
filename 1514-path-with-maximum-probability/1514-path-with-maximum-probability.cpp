class Solution {
    using NODE = int;
    using DISTANCE = double;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        std::unordered_map<int, std::set<std::pair<NODE, DISTANCE>>> adj_list;
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].insert({edges[i][1], succProb[i]});
            adj_list[edges[i][1]].insert({edges[i][0], succProb[i]});
        }
    
        std::unordered_map<NODE, DISTANCE> dist_map;
        std::priority_queue<std::pair<DISTANCE, NODE>> q;
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

        return dist_map[end_node];
    }
};