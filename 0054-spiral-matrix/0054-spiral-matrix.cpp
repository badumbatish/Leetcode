class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        int rows = matrix.size();
        int columns = matrix[0].size();
        int up = 0, left = 0, right = columns - 1, down = rows - 1;

        while (result.size() < rows * columns) {
            for (int col = left; col <= right; col++) result.push_back(matrix[up][col]);
            for (int row = up + 1; row <= down; row++) result.push_back(matrix[row][right]);
            
            if (up != down)
                for (int col = right - 1; col >= left; col--)
                    result.push_back(matrix[down][col]);

            if (left != right) 
                for (int row = down - 1; row > up; row--)
                    result.push_back(matrix[row][left]);

            left++; right--;
            up++; down--; 
        }
        return result;
    }
};