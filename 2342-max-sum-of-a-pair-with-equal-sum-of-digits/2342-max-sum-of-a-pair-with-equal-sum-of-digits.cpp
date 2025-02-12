#include <ranges>
class Solution {
    int sum(int i) {
        int result = 0;
        while (i) {
            result += i % 10;
            i /= 10;
        }
        return result;
    }
public:
    int maximumSum(vector<int>& nums) {
        std::map<int, std::vector<int>> mp;
        for (auto num : nums) {
            mp[sum(num)].push_back(num);
        }
        
        for (auto& [ch, v] : mp | std::views::reverse) {
            std::ranges::sort(v);
            if (v.size() >= 2) return v[v.size() - 2] + v[v.size() - 1];
        }
        return -1;
    }
};