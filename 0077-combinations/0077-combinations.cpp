class Solution {
    std::vector<std::vector<int>> result;
    std::vector<int> temp;
    int n;
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        dfs(1, k);
        return result;
    }

    void dfs(int i, int k){ 
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for (int x = i; x <= n; x++) {
            temp.push_back(x);
            dfs(x + 1, k);
            temp.pop_back();
        }
    
    }
};