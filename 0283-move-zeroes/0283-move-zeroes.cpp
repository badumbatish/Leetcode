class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int move_into = 0;
        int potential_movers = 1;
        while (potential_movers < nums.size()) {
            if (nums[potential_movers] != 0) {
                std::swap(nums[potential_movers], nums[move_into++]);
            }
            potential_movers++;
        }
    }
};