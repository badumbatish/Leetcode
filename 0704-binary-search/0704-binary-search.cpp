class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = -1, high = nums.size() - 1;

        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) high = mid;
            else low = mid;
        }
        
        return nums[high] != target ? -1 : high;
    }
};