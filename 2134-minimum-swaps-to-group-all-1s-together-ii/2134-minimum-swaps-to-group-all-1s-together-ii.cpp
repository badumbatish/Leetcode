class Solution {
public:
    int minSwaps(vector<int>& nums) {
        std::array<int, 2> window = {0, 0};
        int ones = std::ranges::count_if(nums, [](int i){ return i == 1;});
    
        for (int i = 0; i < ones; i++) window[nums[i]]++;
        
        int min_swap = window[0];
        for (int i = ones; i < nums.size() + ones;  i++) {
            int window_right = i % nums.size(), window_left = (i - ones) % nums.size();
            window[nums[window_right]]++;
            window[nums[window_left]]--;
            min_swap = min(min_swap, window[0]);
        }

        return min_swap;
    }
};