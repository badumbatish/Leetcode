class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::unordered_map<std::string, int> mp;

        for (auto str : arr) mp[str]++;

        std::vector<std::string> result;
        for (auto str : arr) {
            if (mp[str]==1) result.push_back(str);
        }
        if (result.size() < k) return "";
        return result[k-1];
    }
};