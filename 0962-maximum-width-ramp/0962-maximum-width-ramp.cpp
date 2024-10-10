class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;  // Monotonic decreasing stack of indices

        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[stack.back()] > nums[i]) {
                stack.push_back(i);
            }
        }

        int maxWidth = 0;

        // Step 2: Traverse from right to left to find the maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) {
                maxWidth = max(maxWidth, j - stack.back());
                stack.pop_back();
            }
        }

        return maxWidth;
    }
};
