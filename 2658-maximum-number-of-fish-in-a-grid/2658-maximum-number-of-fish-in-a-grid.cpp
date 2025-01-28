class Solution {
    int calculate_fishes(std::vector<std::vector<int>> &grid, std::vector<std::vector<bool>> &visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col])
            return 0;
        
        visited[row][col] = true;
        return grid[row][col] + calculate_fishes(grid, visited, row, col + 1) + 
         calculate_fishes(grid, visited, row, col - 1) + 
          calculate_fishes(grid, visited, row + 1, col) + 
           calculate_fishes(grid, visited, row -1, col);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int max_fishes_count = 0;

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 0 && !visited[row][col])
                    max_fishes_count = std::max(max_fishes_count, calculate_fishes(grid, visited, row, col));
            }
        }

        return max_fishes_count;
    }
};