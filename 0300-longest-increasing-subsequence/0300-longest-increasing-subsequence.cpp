class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp = std::vector<int>(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        return *std::ranges::max_element(dp);
    }
};