#include <ranges>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            auto a = numbers[start], b = numbers[end];
            
            if (a + b > target) end--;
            else if (a + b < target) start++;
            else return {start + 1, end + 1};
        }
        return {};
    }
};