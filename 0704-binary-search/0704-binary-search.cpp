class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Consider our predicate that from middle to left is always < target
            // and middle to right is always >
            int middle = (left + right) / 2;

            int comp_target = nums[middle];
            if (target < comp_target) {
                right = middle - 1;
            } else if (target > comp_target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
};