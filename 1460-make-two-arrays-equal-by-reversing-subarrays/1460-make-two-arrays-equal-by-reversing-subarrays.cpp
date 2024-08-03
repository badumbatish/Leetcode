class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        std::map<int, int> mp;

        for (auto num : target) mp[num]++;
        for (auto num : arr) {
            mp[num]--;
            if (mp[num] < 0) return false;
        }
        return true;
    }
};