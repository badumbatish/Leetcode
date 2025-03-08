class Solution {
    using Result = std::vector<std::vector<int>>;
    using Combination = std::vector<int>;

    Result result;
    Combination temp_combination; 
    int target;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       this->target = target; 
        dfs(0, 0, candidates);
       return result;
    }

    void dfs(int index, int sum, std::vector<int>& candidates) {
        if (sum > target) return;
        else if (sum == target) {
           result.push_back(temp_combination);
           return;
        }  else {
            for (int i = index; i < candidates.size(); i++) {
                temp_combination.push_back(candidates[i]);
                dfs(i, sum + candidates[i], candidates);
                temp_combination.pop_back();
            }
        }
        
    }
};