#include <ranges>
using namespace std::ranges;
using namespace ranges::views;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        std::vector<int> left{height.front()}, right{height.back()};

        for (auto ht : height | drop(1)) 
            left.push_back(std::max(left.back(), ht));
        
        for (auto ht : height | views::reverse | drop(1)) 
            right.push_back(std::max(right.back(), ht));
        std::ranges::reverse(right);

        for (auto [i, ht] : std::ranges::views::enumerate(height)) {

            ans += std::min(left[i], right[i]) - ht;
        }
        return ans;
    }
};