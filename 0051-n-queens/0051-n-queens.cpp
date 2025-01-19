class Solution {
    std::vector<std::string> temp;
    std::vector<std::vector<std::string>> result;
    std::unordered_set<int> diags, anti_diags, cols;
    int n = 0;
public:
    void backtrack(int row) {
        if (row == n) {
            result.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            int curr_diag = row - col;
            int curr_anti_diag = row + col;

            if (cols.contains(col) || diags.contains(curr_diag) || anti_diags.contains(curr_anti_diag))
                continue;
            
            cols.insert(col); 
            diags.insert(curr_diag);
            anti_diags.insert(curr_anti_diag);

            temp[row][col] = 'Q';

            backtrack(row + 1);

            temp[row][col] = '.';
            cols.erase(col); 
            diags.erase(curr_diag);
            anti_diags.erase(curr_anti_diag);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        temp = std::vector<std::string>(n, std::string(n, '.'));
        this->n = n; 
        backtrack(0);
        return result;
    }
};