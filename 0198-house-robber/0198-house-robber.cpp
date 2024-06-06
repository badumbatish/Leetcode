class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int amount = nums[1];

        int c1 = nums[1];
        int c2 = nums[0];

        for (int i = 2; i < nums.size(); i++) {
            amount = max(c2 + nums[i], c1);
            c2 = max(c2, c1);
            c1 = amount;
        }

        return amount;
    }
};