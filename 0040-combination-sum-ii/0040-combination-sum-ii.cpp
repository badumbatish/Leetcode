class Solution {
private:
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    int target;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        std::ranges::sort(candidates);

        dfs(candidates, 0, 0);

        return result;
    }

    void dfs(std::vector<int>&candidates, int current, int start) {
        if (current == target) {
            result.push_back(temp);
        } else if (current < target) {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                dfs(candidates, current + candidates[i], i + 1);
                temp.pop_back();
            }
        }
    }
};