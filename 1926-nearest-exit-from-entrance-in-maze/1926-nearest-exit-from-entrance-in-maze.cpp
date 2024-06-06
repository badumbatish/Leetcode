class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        std::vector<std::pair<int, int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        // Mark the entrance as visited since its not a exit.
        int start_row = entrance[0], start_col = entrance[1];

        maze[start_row][start_col] = '+';

        std::queue<std::array<int, 3>> queue;
        queue.push({start_row, start_col, 0});

        while (!queue.empty()) {
            auto [cur_row, cur_col, cur_distance] = queue.front();

            queue.pop();

            for (auto [row_dis, col_dis] : dirs) {
                int next_row = cur_row + row_dis;
                int next_col = cur_col + col_dis;

                if (0 <= next_row && next_row < rows && 0 <= next_col && next_col < cols && 
                    maze[next_row][next_col] == '.') {
                        if (next_row == 0 || next_row == rows - 1 || next_col == 0 || 
                        next_col == cols - 1) {
                            return cur_distance + 1;
                        }

                        maze[next_row][next_col] = '+';
                        queue.push({next_row, next_col, cur_distance + 1});
                }
            }

        }
        return -1;
    }
};