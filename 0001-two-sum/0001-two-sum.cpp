#include <ranges>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> mp;
        for (auto [i, num] : std::ranges::views::enumerate(nums)) {
            if (mp.contains(target-num)) return {mp[target-num], (int)i};

            mp[num] = i;
        }

        return {-1, -1};
    }
};