class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> u_mp;

        for (auto num : arr) u_mp[num] += 1;
        

        std::unordered_set<int> u_set;

        for (auto [key, value] : u_mp) u_set.insert(value);
        

        return u_mp.size() == u_set.size();
    }
};