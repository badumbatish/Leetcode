class Solution {
public:
    int minSwaps(vector<int>& nums) {
        std::map<int, int> window;
        int ones = std::ranges::count_if(nums, [](int i){ return i == 1;});
        int zeroes = nums.size() - ones;

        for (int i = 0; i < ones; i++) {
            window[nums[i]]++;
        }
        int min_swap = window[0];
        for (int i = ones; i < nums.size() * 2 - 1;  i++) {
            int mod_index = i % nums.size();
            int mod_index_minus = (i - ones) % nums.size();
            window[nums[mod_index]]++;
            window[nums[mod_index_minus]]--;
            min_swap = min(min_swap, window[0]);
        }

        return min_swap;
    }
};