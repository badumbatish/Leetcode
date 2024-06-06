class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(),  cols = maze[0].size();

        std::vector<std::pair<int, int>> dirs = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        // Mark the entrance as visited since its not a exit.
        int start_row = entrance[0], start_col = entrance[1];

        maze[start_row][start_col] = '+';

        // Start BFS from the entrance, and use a queue `queue` to store all 
        // the cells to be visited.
        std::queue<std::array<int, 3>> queue;
        queue.push({start_row, start_col, 0});

        while (!queue.empty()) {
            auto [cur_row, cur_col, cur_distance] = queue.front();

            queue.pop();

            // For the current cell, check its four neighbor cells.

            for (auto [row_dis, col_dis] : dirs) {
                int next_row = cur_row + row_dis;
                int next_col = cur_col + col_dis;

                // If there exists an unvisited empty neighbor:
                if (0 <= next_row && next_row < rows && 0 <= next_col && next_col < cols && 
                    maze[next_row][next_col] == '.') {

                        // If this empty cell is an exit, return distance + 1.

                        if (next_row == 0 || next_row == rows - 1 || next_col == 0 || 
                        next_col == cols - 1) {
                            return cur_distance + 1;
                        }

                        // Otherwise, add this cell to 'queue' and mark it as visited.
                        maze[next_row][next_col] = '+';
                        queue.push({next_row, next_col, cur_distance + 1});
                }
            }

        }
        return -1;
    }
};