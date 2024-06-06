class Solution {
private:
    std::string digits;
    std::string temp = {};
    std::vector<std::string> result;
    std::map<char, std::string> levels = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };


public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        dfs(0);

        return result;
    }

    void dfs(int level) {
        if (temp.size() == digits.size() && temp.size() != 0) {
            result.push_back(temp);
            return;
        }
        
        for (auto ch : levels[digits[level]]) {
            temp.push_back(ch);
            dfs(level + 1);
            temp.pop_back();
        }
    }
}; 