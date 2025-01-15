class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums.front();
        int max_sum = nums.front();

        for (int i = 1; i < nums.size(); i++) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            max_sum = max(curr_sum , max_sum);
        }

        return max_sum;
    }
};