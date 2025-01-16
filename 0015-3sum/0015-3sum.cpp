#include <ranges>
using namespace ranges;
using namespace views;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);
        
        // -1 -1 2 3 

        // c = 0 - a - b = 0 - (a + b);

        std::vector<std::vector<int>> v;
        for (int i = 0; i < nums.size() - 2; i++) { // a
            if (i > 0 && nums[i] == nums[i-1]) continue;
            std::cout << "Enter\n";
            std::unordered_map<int, int> mp;
           for (int j = i + 1; j < nums.size(); j++) { // b
            int compliment = - (nums[i] + nums[j]);
            if (mp.contains(compliment) && mp[compliment] != j) {
                v.push_back({nums[i], compliment, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;

            }
            mp[nums[j]] = j;
           }
        }
        return v;
    }
};