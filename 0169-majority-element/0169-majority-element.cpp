class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityCount = nums.size() / 2;
        while (true) {
            int candidate = nums[rand() % nums.size()];
            if (std::ranges::count_if(nums, [&](auto num) { return candidate == num; }) > majorityCount) {
                return candidate;
            }
        }
    }
};