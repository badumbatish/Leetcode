class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        std::vector<double> max_prob(n, 0);
        max_prob[start_node] = 1.0;

        for (int i = 0; i < n - 1; i++) {
            auto has_update = false;
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0], v = edges[j][1];
                double path_prob = succProb[j];

                if (max_prob[u] * path_prob > max_prob[v]) {
                    max_prob[v] = max_prob[u] * path_prob;
                    has_update = true;
                }
                if (max_prob[v] * path_prob > max_prob[u]) {
                    max_prob[u] = max_prob[v] * path_prob;
                    has_update = true;
                }
            }

            if (!has_update) break;
        }

        return max_prob[end_node];
    }
};