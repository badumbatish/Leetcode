class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 2) return *std::ranges::max_element(nums);

        auto two_away = nums[0];
        auto one_away = nums[1];

        auto amount = max(two_away, one_away);
        for(size_t i = 2; i < nums.size(); i++) {
            amount = max(two_away + nums[i], one_away);

            two_away = max(two_away, one_away);
            one_away = amount;
        }
        
        return amount;
    }
};