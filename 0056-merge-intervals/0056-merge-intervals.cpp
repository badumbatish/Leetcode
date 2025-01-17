#include <ranges>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals);
        vector<vector<int>> result; 
        result.push_back(intervals.front());
        for (auto interval : intervals) {
            // if doesn't clash
            if (result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                result.back()[1] = std::max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};