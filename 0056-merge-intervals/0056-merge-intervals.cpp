class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b) { return a[0] < b[0]; });

        std::vector<std::vector<int>> output;
        output.push_back(intervals.front());

        for (auto current_interval : intervals) {
            auto last_interval = output.back();
            if (last_interval[1] < current_interval[0]) {
                output.push_back(current_interval);
            } else {
                output.back()[1] = std::max(output.back()[1],current_interval[1]);
            }
        }

        return output;
    }
};