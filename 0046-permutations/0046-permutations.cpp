class Solution {
private:
    int l = 0;
    std::vector<std::vector<int>> result = {};
    std::vector<int> temp = {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        l = nums.size();

        dfs_helper(nums);

        return result;
    }

    void dfs_helper(std::vector<int> &nums) {
        if (temp.size() == l) {
            result.push_back(temp);
        } else {
            for (auto item : nums) {
                // If the temp array doesn't contain the specific item, we can add it.
                if (std::find(temp.begin(), temp.end(), item) == temp.end()) {
                    temp.push_back(item);
                    dfs_helper(nums);
                    temp.pop_back();
                }
            }
        }
    }
};