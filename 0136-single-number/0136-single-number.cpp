class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::accumulate(std::begin(nums), std::end(nums), 0, [](int a, int b) { return a ^ b; });
    }
};