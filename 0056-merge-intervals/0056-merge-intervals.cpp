class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals, [](auto &a, auto &b) { return a[0] < b[0]; });

        std::vector<int> temp = intervals[0];

        std::vector<std::vector<int>> ans = {temp};
        
        for (auto &interval : intervals) {
            auto& last_interval = ans.back();
            if (interval[0] > last_interval[1] )  {
                ans.push_back(interval);
            } else {
                last_interval[1] = std::max(last_interval[1], interval[1]);
            }
        }
        return ans;
    }
};