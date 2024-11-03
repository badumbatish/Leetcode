class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time =0;
        std::priority_queue<int, std::vector<int>> pq = {};

        std::map<char, int> mp;
        for (auto ch : tasks) mp[ch]++;

        for (auto [key, value] : mp) pq.push({value});

        while (! pq.empty()) {
            int cycle = n + 1;
            std::vector<int> store;

            int task_count = 0;

            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) 
                    store.push_back(pq.top() - 1);
                pq.pop();
                task_count++;
            }
            for (auto freq : store) pq.push(freq);

            time += (pq.empty() ? task_count : n + 1);
        }

        return time;


        return time;
    }
};