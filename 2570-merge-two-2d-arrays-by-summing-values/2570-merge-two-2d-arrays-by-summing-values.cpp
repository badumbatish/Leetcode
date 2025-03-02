class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        std::map<int, int> id_val;
        for (auto v : nums1) {
            int a = v[0], b = v[1];
            id_val[a]+=b;
        }
        for (auto v : nums2) {
            int a = v[0], b = v[1];
            id_val[a]+=b;
        }

        std::vector<std::vector<int>> result;
        for (auto [id, val] : id_val) {
            result.push_back({id, val});
        }
        return result;
    }
};