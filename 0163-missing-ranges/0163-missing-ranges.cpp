class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return {{lower, upper}};
        if (nums.back() < upper) nums.push_back(upper+1);
        std::vector<std::vector<int>> result;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= lower && nums[i] <= upper) {
                    if (nums[i] + 1 != nums[i+1]) {
                        result.push_back({nums[i]+1, nums[i+1]-1});
                    } 
            }
        }
    
        return result;
    }
};