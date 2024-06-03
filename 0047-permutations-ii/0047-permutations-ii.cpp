class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    std::map<int, int> mp;
    int length = 0;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto i : nums) mp[i]++;
        length = nums.size();
        recursive();

        return result;
    }

    void recursive() {
        if (temp.size() == length) {
            result.push_back(temp);
            return;
        }

        for (auto &[key, cnt] : mp) {
            if (cnt == 0) continue;

            temp.push_back(key); cnt--;
            recursive();
            temp.pop_back(); cnt++;
        }
    }
};