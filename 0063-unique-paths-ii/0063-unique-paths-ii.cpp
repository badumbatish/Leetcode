class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int>> unique_paths(m, std::vector<int>(n, 0));

        int i = 0;
        while (i < m) {
            // Have an obstacle, anything after this is not cool
            if (obstacleGrid[i][0] == 1) {
                for (; i < m; i++) unique_paths[i][0] = 0;

            } else {
                unique_paths[i][0] = 1;
                i++;
            }
        }

        i = 0;
        while (i < n) {
            // Have an obstacle, anything after this is not cool
            if (obstacleGrid[0][i] == 1) {
                for (; i < n; i++) unique_paths[0][i] = 0;

            } else {
                unique_paths[0][i] = 1;
                i++;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) unique_paths[i][j] = 0;
                else unique_paths[i][j] = unique_paths[i-1][j] + unique_paths[i][j-1];
            }
        }

        return unique_paths[m-1][n-1];

    }
};