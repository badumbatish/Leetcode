class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> ump1, ump2;

        for (auto i : nums1) ump1[i]++;
        for (auto i : nums2) ump2[i]++;

        std::vector<int> ans;
        for (auto& [num, freq] : ump1) {
            if (ump2[num] != 0) {
                auto v = std::vector<int>(min(freq, ump2[num]), num);
                ans.insert(ans.end(), v.begin(), v.end());
            }
        }

        return ans;
    }
};