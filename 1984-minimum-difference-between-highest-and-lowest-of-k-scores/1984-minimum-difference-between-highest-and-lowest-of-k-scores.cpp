class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        std::ranges::sort(nums);

        int diff = INT_MAX;
        for (int i = 1; i < nums.size() ;i ++) {
            diff = std::min(nums[i]- nums[i-1], diff);
        }
        
        return diff;
    }
};