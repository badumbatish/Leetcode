class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        size_t expected_len = 0;
        for (auto &word : words) {
            expected_len = std::max(expected_len, word.size());
        }

        for (auto &word : words) {
            while (word.size() < expected_len) word+=" ";
        }
        while (words.size() < expected_len) 
            words.push_back(std::string(' ', expected_len));


        for (int i = 0; i < words.size(); i++) {
            
            for (int j = 0; j < words.size(); j++) {
                if (words[i][j] != words[j][i]) return false;
            }
        }

        return true;
    }
};