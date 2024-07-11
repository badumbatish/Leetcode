class Solution {
    using tup = std::tuple<int, int>;
    std::vector<tup> adj[101];

    void dijkstr(std::vector<int> &signal_received_at, int source, int n) {
        std::priority_queue<tup, std::vector<tup>, greater<tup>> pq;
        pq.push({0, source});

        signal_received_at[source] = 0;

        while (!pq.empty()) {
            auto [curr_node_time, curr_node] = pq.top();
            pq.pop();
            if (curr_node_time > signal_received_at[curr_node]) continue;

            for (auto &[time, neighbor_node] : adj[curr_node]) {
                if (signal_received_at[neighbor_node] > curr_node_time + time) {
                    signal_received_at[neighbor_node] = curr_node_time + time;
                    pq.push({signal_received_at[neighbor_node], neighbor_node});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto &time : times) {
            int source = time[0];
            int dest = time[1];

            int travel_time = time[2];

            adj[source].push_back({travel_time, dest});
        }
        std::vector<int> signal_received_at(n+1, INT_MAX);

        dijkstr(signal_received_at, k, n);

        int answer= INT_MIN;

        for (int i = 1;i <= n; i++) {
            answer = std::max(answer, signal_received_at[i]);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};