class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int max_sum = nums.front();
        int current_sum = nums.front();

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] >= nums[i]) {
                current_sum = nums[i];
            } else current_sum += nums[i];
            max_sum = std::max(max_sum, current_sum);
        }
        return max_sum;
    }
};