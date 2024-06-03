class Solution {
    using v_int = std::vector<int>;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<v_int> result = {};
        v_int temp = {};
        dfs_helper(temp, nums, result);
        return result;
    }

    void dfs_helper(v_int &temp, v_int & nums, std::vector<v_int> &result) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
        } else {
            for (auto item : nums) {
                if  (std::find(temp.begin(), temp.end(), item) == temp.end()) {
                        temp.push_back(item);
                        dfs_helper(temp, nums, result);
                        temp.pop_back();
                }
            }
        }
    }
};