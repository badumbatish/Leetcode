class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_min = nums[0], min_sum = nums[0];
        int curr_max = nums[0], max_sum = nums[0];

        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_min = std::min(curr_min + nums[i], nums[i]);
            min_sum = std::min(curr_min, min_sum);

            curr_max = std::max(curr_max + nums[i], nums[i]);
            max_sum = std::max(curr_max, max_sum);

            std::cout << max_sum << " " << min_sum << std::endl;
            sum += nums[i];
        }
        
        if (sum == min_sum) return max_sum;
        return std::max(max_sum, sum - min_sum);
    }
};