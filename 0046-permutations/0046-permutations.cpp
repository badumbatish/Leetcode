class Solution {
private:
    int l = 0;
    std::vector<std::vector<int>> result = {};
    std::vector<int> temp = {};
    std::map<int, int> mp = {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        l = nums.size();
        for (auto item : nums) {
            mp[item]++;
        }

        dfs_helper(nums);

        return result;
    }

    void dfs_helper(std::vector<int> &nums) {
        if (temp.size() == l) {
            result.push_back(temp);
            return;
        } 

        for (auto &[key, value] : mp) {
            // If the temp array doesn't contain the specific item, we can add it.
            if (value != 0) {
                value--;
                temp.push_back(key);
                dfs_helper(nums);
                temp.pop_back();
                value++;
            }
        }
        
    }
};