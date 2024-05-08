class Solution {
    std::vector<std::vector<int>> result;
    std::unordered_map<int, int> mp;
    std::vector<int> temp;
    int len = 0;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();
        for (auto i : nums) mp[i]++;
        recursive();

        return result;
    }

    void recursive() {
        if (temp.size() == len) {
            result.push_back(temp);
            return;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            char ch = it->first;

            // the value == 0 means we ran out of this choice,
            // we really should pick another option in the map
            if (it->second == 0) continue;
            
            // Use the option
            temp.push_back(ch);

            // Mark that we use it
            it->second--;

            // Go to the next empty place where we haven't use the option
            recursive();

            // Un-use the option
            temp.pop_back();

            // Mark that we un-use it.
            it->second++;
        }
    }
};