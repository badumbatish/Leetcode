class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::ranges::sort(nums);

        return nums;
    }
};