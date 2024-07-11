class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (auto &num : nums1) {
            int index = std::ranges::find(nums2, num) - nums2.begin();

            bool minus_one = true;
            for (int i = index + 1; i < nums2.size(); i++) {
                if (nums2[i] > nums2[index]) {
                    num = nums2[i];
                    minus_one = false;
                    break;
                }
            }
            if (minus_one) num = -1;
        }


        return nums1;
    }
};