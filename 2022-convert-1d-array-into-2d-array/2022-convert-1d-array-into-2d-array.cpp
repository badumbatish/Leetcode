class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        std::vector<std::vector<int>> result(m, std::vector<int>());
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cout << (i+j) << std::endl;
        //         result[i].push_back(original[i+j]);
        //     }
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         std::cout << original[j+ i * m] << std::endl;
        //         result[j].push_back(original[j+i*m]);
        //     }
        // }
        for (int i = 0; i < m; i++) {
            for (int j =0; j< n; j++) {
                result[i].push_back(original[i*n + j]);
            }
        }
        return result;
    }
};