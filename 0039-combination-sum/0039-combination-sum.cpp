class Solution {
    int target;
    std::vector<std::vector<int>> result;
    std::vector<int> temp;

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>&candidates, int target) {
        this->target = target;

        helper(0, candidates, 0);

        return result;
    }


    void helper(int sum, std::vector<int> &candidates, int start) {
        if (sum == target) {
            result.push_back(temp);
        } else if (sum < target) {
            for (int i = start; i < candidates.size(); i++) {
                temp.push_back(candidates[i]);
                helper(sum + candidates[i], candidates, i);
                temp.pop_back();
            }
        }

        return;
    }
};