class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<std::vector<int>> unique_paths(m, std::vector<int>(n, 0));

        int i = 0;
        bool no_obstacle = true;
        // first column's row
        for (int i = 0; i < m; i++) {
            // Have an obstacle, anything after this is not cool
            no_obstacle &= obstacleGrid[i][0] == 0;
            unique_paths[i][0] = no_obstacle;
        }

        // first row's columns
        no_obstacle = true;
        for (int i = 0; i < n; i++) {
            // Have an obstacle, anything after this is not cool
            no_obstacle &= obstacleGrid[0][i] == 0;
            unique_paths[0][i] = no_obstacle;
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