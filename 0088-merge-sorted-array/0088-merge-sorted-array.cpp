class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums1copy(nums1.begin(), nums1.begin() + m);

        int p1 = 0;
        int p2 = 0;

        for (int p = 0; p < m + n; p++) {
            if (p2 >= n || (p1 < m && nums1copy[p1] < nums2[p2])) {
                nums1[p] = nums1copy[p1++];
            } else {
                nums1[p] = nums2[p2++];
            }
        }
    }
};