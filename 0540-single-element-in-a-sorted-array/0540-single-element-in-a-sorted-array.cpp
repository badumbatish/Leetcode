class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool havles_are_even = (hi - mid) % 2 == 0;

            if (nums[mid + 1] == nums[mid]) {
                if (havles_are_even) lo = mid + 2;
                else hi = mid - 1;
            } else if (nums[mid - 1] == nums[mid]) {
                if (havles_are_even) hi = mid - 2;
                else lo = mid + 1;
            } else return nums[mid];
        }
        return nums[lo];

    }

};