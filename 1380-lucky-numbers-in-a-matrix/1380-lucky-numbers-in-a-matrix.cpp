class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        std::vector<int> a;
        std::vector<int> max_row;
        std::vector<int> max_col;
        for (int i = 0; i < matrix.size(); i++) {
            max_row.push_back(*std::min_element(matrix[i].begin(), matrix[i].end()));
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            int maxi = 0;
            for (int i = 0; i < matrix.size(); i++) {
                maxi = std::max(maxi, matrix[i][j]);
            }
            max_col.push_back(maxi);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == max_row[i] &&matrix[i][j] == max_col[j]) {
                    a.push_back(matrix[i][j]);
                }
            }
        }

        return a;
    }
};