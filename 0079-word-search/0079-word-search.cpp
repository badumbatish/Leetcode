class Solution {
private:
    using XY = std::pair<int, int>;
    const std::vector<XY> directions = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = '.';
                    if (find(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = ch;
                }
            }
        }
        return false;
    }

private:
    bool find(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        if (index == word.length()) return true;
        
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;

            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[index]) {
                char ch = board[x][y];
                board[x][y] = '.';
                if (find(board, word, x, y, index + 1)) return true;
                board[x][y] = ch;
            }
        }

        return false;
    }
};