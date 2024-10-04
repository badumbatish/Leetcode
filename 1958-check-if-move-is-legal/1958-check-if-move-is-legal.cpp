class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        // Array of directions: {row direction, column direction}
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                                             {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        char oppositeColor = (color == 'W') ? 'B' : 'W';
        
        // Check all 8 directions
        for (auto& dir : directions) {
            int row = rMove + dir.first;
            int col = cMove + dir.second;
            bool foundOpposite = false;
            
            // Traverse in the current direction
            while (row >= 0 && row < 8 && col >= 0 && col < 8) {
                if (board[row][col] == '.') {
                    break;  // Found an empty space, invalid direction
                }
                if (board[row][col] == color) {
                    if (foundOpposite) {
                        return true;  // Found a good line
                    } else {
                        break;  // Found same color too soon, invalid direction
                    }
                }
                if (board[row][col] == oppositeColor) {
                    foundOpposite = true;  // Found the opposite color
                }
                
                // Move to the next cell in this direction
                row += dir.first;
                col += dir.second;
            }
        }
        
        return false;  // No valid direction found
    }
};
