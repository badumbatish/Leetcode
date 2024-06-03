class Solution {
public:
    void moveZeroes(std::vector<int> & nums) {
        int fast_ptr = 0;
        int slow_ptr = 0;

        for (; fast_ptr < nums.size(); fast_ptr++) {
            if (nums[fast_ptr] != 0) {
                swap(nums[fast_ptr], nums[slow_ptr++]);
            }
        }
    }
};