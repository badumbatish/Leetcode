class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
        int count = 0;
        for (int row = 0; row < (n+1) / 2; row++) {
            std::cout << "New loop, count is at " << count << std::endl;
            for (int col = 0; col < n / 2; col++) {
                std::cout << "Touching " << row << " " << col << std::endl;
                int temp = matrix[n - 1 - col][row];
                matrix[n-1 -col][row] = matrix[n-1-row][n-col-1];
                matrix[n-1-row][n-col-1] = matrix[col][n-1-row];
                matrix[col][n -1 -row] = matrix[row][col];
                matrix[row][col] = temp;
                v[n-1 -col][row] = count++;
                v[n-1-row][n-col-1] = count++;
                v[col][n-1-row] = count++;
                v[row][col] =  count++;
            }
        }
        
        for (auto x : v ){
            for (auto num : x) {
                std::cout << num << "\t";
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
        return;
    }
};