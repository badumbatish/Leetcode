using pi = std::pair<int, int>;
class Solution {
    std::vector<std::vector<pi>> adj_list;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        adj_list = std::vector<std::vector<pi>>(26);

        int conversion_count = original.size();
        for (int i = 0; i < conversion_count; i++) 
            adj_list[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        
        std::vector<std::vector<long long>> min_conversion_cost(26, std::vector<long long>(26));
        for (int i = 0; i < 26; i++) 
            min_conversion_cost[i] = dijkstra(i);

        long long total_cost = 0;
        int char_count = source.size();

        for (int i = 0; i < char_count; i++) {
            if (source[i] != target[i]) {
                long long char_conv_cost = min_conversion_cost[source[i]-'a'][target[i]-'a'];
                if (char_conv_cost == -1) return -1;
                total_cost += char_conv_cost;
            }
        }

        return total_cost;
    }

    std::vector<long long> dijkstra(int source) {
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>,
            std::greater<std::pair<long long, int>>> pq;

        pq.push({0, source});
        std::vector<long long> min_cost(26, -1);

        while (!pq.empty()) {
            auto [current_cost, current_char] = pq.top(); pq.pop();

            if (min_cost[current_char] != -1 && min_cost[current_char] < current_cost) continue;

            for (auto &[target, conv_cost] : adj_list[current_char]) {
                long long new_total_cost = current_cost + conv_cost;
                if (min_cost[target] == -1 || new_total_cost < min_cost[target]) {
                    min_cost[target] = new_total_cost;
                    pq.push({new_total_cost, target});
                }
            }
        }

        return min_cost;
    }
};