class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums1_copy(nums1.begin(), nums1.begin() + m);

        int p1 = 0, p2 = 0;

        int p = 0;
        while (p1 < m && p2 < n) {
            if (nums1_copy[p1] < nums2[p2]) nums1[p++] = nums1_copy[p1++];
            else nums1[p++] = nums2[p2++];
        }

        while (p1 < m) nums1[p++] = nums1_copy[p1++];
        while (p2 < n) nums1[p++] = nums2[p2++];
    }
};