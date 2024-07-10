class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        std::ranges::sort(intervals);

        auto Q = queries;
        std::ranges::sort(Q);

        std::priority_queue<std::vector<int>> pq;
        std::unordered_map<int, int> res;

        int i = 0, n = intervals.size();

        for (int q : Q) {
            while (i < n && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                i++;
                pq.push({l - r - 1, r});
            }

            while (pq.size() && pq.top()[1] < q) pq.pop();

            res[q] = pq.size() ? -pq.top()[0] : -1;
        }

        std::vector<int> ans;

        for (int q : queries) ans.push_back(res[q]);

        return ans;
    }
};