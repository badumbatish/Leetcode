class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Run heuristic first
            // Create a map of all character in board
        auto board_count = std::map<char, int>();
        for(int8_t row=0; row < board.size(); row++) {
            for (int8_t col=0; col < board[0].size(); col++) {
                board_count[board[row][col]]++;
            }
        }
            // Create a map of all characters in word
        auto word_count = std::map<char, int>();
        for (auto ch : word) word_count[ch]++;

        for (auto it=word_count.begin(); it != word_count.end(); it++) {
            // if the count of word is more than board, we know it's impossible
            if (word_count[it->first] > board_count[it->first]) return false;
        }
        // make a marking array
        for(int8_t row=0; row < board.size(); row++) {
            for (int8_t col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0]) {
                    if (helper(row, col, word, 0, board)) return true;
                }
            }
        }
        return false;
    }

    bool helper(int8_t row, int8_t col, std::string& word,
     int8_t index, vector<vector<char>>& board) {
        if (index >= word.size()) return true;

        if (row < 0 || row == board.size() || 
            col < 0 || col == board[0].size() || board[row][col] != word[index]) {
                return false;
            }

        bool return_val = false;

        board[row][col] = '#';
        static std::vector<int> dir = {-1, 0, 1, 0 , -1};

        for (int i = 0; i < 4; i++) {
            return_val = helper(row + dir[i], col + dir[i+1], word, index+1, board);
            if (return_val) break;
        }

        board[row][col] = word[index];
        return return_val;
    }
};