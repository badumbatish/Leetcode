class Solution {
private:
    bool visited[301][301] = {false};
    int count = 0;
    int row_size;
    int col_size;
public:
    int numIslands(vector<vector<char>>& grid) {
        row_size = grid.size();
        col_size = grid[0].size();


        //memset(visited, 0, sizeof(visited) );

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == '1' && visited[row][col] == false) {
                    dfs(row, col, grid);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(int row, int col, std::vector<std::vector<char>> &grid) {
        visited[row][col] = true;

        // 0, 1
        // 1, 0
        // -1, 0
        // 0, -1
        static std::vector<int> traverseA = {0, 1, -1, 0};
        static std::vector<int> traverseB = {1, 0, 0, -1};

        for(int i = 0; i < 4; i++) {
            auto a = row+traverseA[i];
            auto b = col+traverseB[i];
            if (isWithin(a, b) && grid[a][b] == '1' && !visited[a][b]) dfs(a, b, grid);
        }
    }

    bool isWithin(int row, int col) {
        auto r = 0 <= row && row < row_size;
        auto c = 0 <= col && col < col_size;

        return r && c;
    }
};