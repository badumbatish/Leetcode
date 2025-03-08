class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    int target; 

    void dfs(std::vector<int>&candidates, int curr, int sum) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = curr; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            sum += candidates[i];

            dfs(candidates, i, sum);

            temp.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        dfs(candidates, 0, 0);
        return result;
    }
};