class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        size_t expected_len = 0;
        for (auto &word : words) expected_len = std::max(expected_len, word.size());
        

        for (auto &word : words) 
            while (word.size() < expected_len) word+=" ";
        

        std::string empty_string(' ',expected_len);
        while (words.size() < expected_len) words.push_back(empty_string);


        for (int i = 0; i < words.size(); i++) {
            
            for (int j = 0; j < words.size(); j++) {
                if (words[i][j] != words[j][i]) return false;
            }
        }

        return true;
    }
};