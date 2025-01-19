class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int first = -1, last = -1;

        // Search for the first occurrence
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1; // Narrow down to the left half
            } else {
                left = mid + 1; // Narrow down to the right half
            }
        }
        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        first = left;

        // Search for the last occurrence
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1; // Narrow down to the right half
            } else {
                right = mid - 1; // Narrow down to the left half
            }
        }
        last = right;

        return {first, last};
    }
};
