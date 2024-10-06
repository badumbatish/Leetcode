class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        std::vector<std::pair<int, int>> ranges;

        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (j == 0 || nums[j] == nums[j-1] + 1) j = j + 1;
            else {
                ranges.push_back({nums[i], nums[j-1]});
                i = j;
                j = j + 1;
            }
        }

        ranges.push_back({nums[i], nums[j-1]});

        std::vector<std::string> result;
        for (auto [start ,end ] : ranges) {
            if (start != end) result.push_back(to_string(start) + "->" + to_string(end));
            else result.push_back(to_string(start));
        }

        return result;
    }
};