class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Lower bound of a number in nums means the first occurrence which is not less than num
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};