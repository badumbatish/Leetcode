class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < (n+1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                
                int temp = matrix[n - 1 - j][i];
                matrix[n-1 -j][i] = matrix[n-1-i][n-j-1];
                matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
                matrix[j][n -1 -i] = matrix[i][j];
                matrix[i][j] = temp;
                v[n-1 -j][i] = count++;
                v[n-1-i][n-j-1] = count++;
                v[j][n-1-i] = count++;
                v[i][j] =  count++;
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