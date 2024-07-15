class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        dfs(nums, 0);
        return result;
    }

    void dfs(std::vector<int>&nums, int start) {
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            result.push_back(temp);
            dfs(nums, i + 1);
            temp.pop_back();
        }
    }
};