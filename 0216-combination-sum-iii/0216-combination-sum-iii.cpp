class Solution {
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    int sum = 0;
    int k, n;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this-> k = k;
        this-> n = n;

        dfs(1);

        return ans;
    }

    void dfs(int level) {
        if (temp.size() == k && sum == n) {
            ans.push_back(temp);
            return;
        }

        if (temp.size() == k && sum > n) return;

        for (int i =  level; i <= 9; i++) {
            temp.push_back(i); sum += i;
            dfs(i+1);
            temp.pop_back(); sum -= i;
        }
    }
};