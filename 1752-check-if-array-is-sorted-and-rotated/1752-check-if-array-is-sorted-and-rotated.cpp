class Solution {
    bool is_rotated_by_k(std::vector<int>& nums, std::vector<int> rotated, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != rotated[(i+k) % nums.size()]) return false;
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        std::vector<int> rotated = nums;
        std::ranges::sort(rotated);

        for (int i = 0; i < nums.size(); i++) {
            if (is_rotated_by_k(nums, rotated, i)) return true;
        }
        return false;
    }
};