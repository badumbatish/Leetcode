class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // copy the nums array -> square it -> sort it 
        auto result = nums;

        for (auto &n : result) n*=n;
        std::ranges::sort(result);
        return result;
    }
};