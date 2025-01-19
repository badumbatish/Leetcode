class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int next_to_decrease = nums.size() -2;
        while(next_to_decrease >= 0) {
            if (nums[next_to_decrease] < nums[next_to_decrease + 1])
                break;
            else next_to_decrease--;
        }
        std::cout << "Index is" << next_to_decrease << std::endl;
        if (next_to_decrease == -1) {
            std::ranges::sort(nums);
            return;
        }
        int n = nums[next_to_decrease];
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > n) {
                std::swap(nums[i], nums[next_to_decrease]);
                std::sort(nums.begin() + next_to_decrease + 1, nums.end());
                break;
            }
        }
    }
};