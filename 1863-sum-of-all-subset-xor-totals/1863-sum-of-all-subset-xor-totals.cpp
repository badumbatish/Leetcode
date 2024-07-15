class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return subset_xor(nums, 0, 0);
    }

    int subset_xor(std::vector<int> &nums, int index, int current_xor) {
        if (index == nums.size()) return current_xor;

        int with_elem = subset_xor(nums, index + 1, current_xor ^ nums[index]);

        int without_elem = subset_xor(nums, index + 1, current_xor);

        return with_elem + without_elem;
    }
};