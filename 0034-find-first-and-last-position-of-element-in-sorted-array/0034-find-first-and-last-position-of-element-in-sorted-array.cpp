class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = 0, right = nums.size() - 1;

        int first = 0;
        while (left <= right) {
            int mid = (left + right) / 2;

            // if target[mid] > target , move down
            // move up
            if (nums[mid] <=target ) {
                first = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        if (first != 0  && nums[first -1] != target ) return {-1, -1};
        if (first == 0 && nums[first] != target) return {-1, -1};
        if (first != 0) first -= 1;
        left = 0, right = nums.size() - 1;
        int second = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] <= target ) {
                second = mid;
                left = mid + 1;
            } else right = mid - 1;
        }


        return {first, second};
    }
};