#include <ranges>
using namespace ranges;
using namespace views;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = nums.front(), best_sum = nums.front();

        for (auto num : nums | drop(1)) {
            curr_sum = std::max(curr_sum + num, num);
            best_sum = std::max(curr_sum, best_sum);
        }
        return best_sum;
    }
};