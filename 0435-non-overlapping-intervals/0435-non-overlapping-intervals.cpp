class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;

        if (intervals.size() == 0) return 0;
        std::sort(intervals.begin(), intervals.end(), [](auto a, auto b){ return a[1] < b[1]; });

        std::vector<int> prev = intervals[0];

        for (auto i : intervals) {
            if (prev[1] > i[0]) ans++;
            else prev = i;
        }

        return ans;
    }
};