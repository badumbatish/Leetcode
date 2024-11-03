class Solution {
    bool visited[301][301] = { false};
    int rows = 0;
    int cols = 0;
    int num_island = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i , j);
                    num_island++;
                }
            }
        }     
        return num_island;
    }

    void dfs(std::vector<std::vector<char>>&grid, int row, int col) {
        grid[row][col] = '0';
        static std::vector<std::tuple<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto [row_dir, col_dir] : dirs) {
            int new_row = row + row_dir, new_col = col + col_dir;
            if (!(0 <= new_row && new_row < rows)) continue;
            if (!(0 <= new_col && new_col < cols)) continue;

            if (grid[new_row][new_col] == '1') dfs(grid, new_row, new_col);
        }
    }
};