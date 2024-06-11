class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (!nums1.empty() && nums1.back() == 0 && nums1.size() > m ) nums1.pop_back();

        for (auto &n : nums2) nums1.push_back(n);

        std::sort(nums1.begin(), nums1.end());

        return;
    }
};