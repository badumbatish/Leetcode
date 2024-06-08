class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        auto delta_dir = std::vector<std::pair<int, int>> { {0, 1}, {0 ,-1}, {1, 0}, {-1, 0}};

        int start_row = entrance[0], start_col = entrance[1];
        maze[start_row][start_col] = '+';
        // row, column, and distance
        std::queue<std::array<int, 3>> q;

        q.push({start_row, start_col, 0});

        while (!q.empty()) {
            auto [cur_row, cur_col, dist] = q.front(); q.pop();

            for (auto [dx, dy] : delta_dir) {
                int row = cur_row + dx;
                int col = cur_col + dy;

                if (0 <= row && row < rows && 0 <= col && col < cols && maze[row][col] == '.') {

                    if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) return dist + 1;

                    maze[row][col] = '+';
                    q.push({row, col, dist + 1});
                }
            }
        }

        return -1;
    }
};