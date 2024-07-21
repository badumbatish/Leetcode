class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Lower bound of a number in nums means the first occurrence which is not less than num
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else right = mid;
        }

        return left;
    }
};