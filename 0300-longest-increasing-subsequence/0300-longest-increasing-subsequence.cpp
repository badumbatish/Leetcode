class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);

        // In the DPV textbook, we define (i, j) to have an edge if nums[j] < nums[i]
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    } 
};