class Solution {
private:
    class Cell {
    public: 
        int height, row, col;
        
        explicit Cell(int height, int row, int col) : height(height), row(row), col(col) {}

        bool operator>(const Cell& other) const {
            return height > other.height;
        }
    };
    int rows, cols;
public:
    bool isValidCell(int row, int col) {
        return 0 <= row && row < rows && 0 <= col && col < cols; 
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        std::array<int, 5> dir = {-1, 0, 1, 0 , -1};
        rows = heightMap.size();
        cols = heightMap[0].size();
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        std::priority_queue<Cell, std::vector<Cell>, std::greater<>> pq;

        for (int i = 0; i < rows; i++) {
            pq.push(Cell(heightMap[i][0], i, 0));
            pq.push(Cell(heightMap[i][cols - 1], i, cols - 1));
            visited[i][0] = visited[i][cols - 1] = true;
        }

        for (int i = 0; i < cols; i++) {
            pq.push(Cell(heightMap[0][i], 0, i));
            pq.push(Cell(heightMap[rows - 1][i], rows - 1, i));
            visited[0][i] = visited[rows - 1][i] = true;
        }

        int total_volume = 0;

        while (!pq.empty()) {
            auto [height, row, col] = pq.top(); pq.pop();

            for (int i = 0; i < 4; i++) {
                int next_row = row + dir[i];
                int next_col = col + dir[i + 1];
                if (isValidCell(next_row, next_col) && !visited[next_row][next_col]) {
                    int next_height = heightMap[next_row][next_col];
                    if (next_height < height) total_volume += (height - next_height);

                    pq.push(Cell(std::max(next_height, height), next_row, next_col));
                    visited[next_row][next_col] = true;
                }
            }
        }
        return total_volume;
    }
};