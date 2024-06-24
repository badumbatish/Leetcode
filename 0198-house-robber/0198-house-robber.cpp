class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        auto amount = nums[1];

        auto c1 = nums[1];
        auto c2 = nums[0];

        for (size_t i = 2; i < nums.size(); i++) {
            // The amount that the thief can get is 
            // The maximum between the 1-away, or 
                // the previous 2-away one, coupled with the current one.
            amount = max(c2 + nums[i], c1);

            // The two-away is the max between the previous two-away and the 1-away
            // (since the house robber can elect to be picky)
            c2 = max(c2, c1);

            // The 1-away is always the amount
            c1 = amount;
        }

        return amount;
    }
};