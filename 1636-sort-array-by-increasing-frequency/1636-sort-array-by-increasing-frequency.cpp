class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (auto n : nums) mp[n]++;

        std::vector<std::pair<int, int>> vec;
        for (auto pair : mp) vec.push_back(pair);

        std::ranges::sort(vec, [](const auto&a, const auto&b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        std::vector<int> res;
        for (auto &[key, value] : vec) {
            while (value != 0) {
                res.push_back(key);
                value--;
            }
        }
        return res;
    }
};