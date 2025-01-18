class Solution {
    std::unordered_map<char, std::string> mp = {
        {'2', {"abc"}},
        {'3', {"def"}},
        {'4', {"ghi"}},
        {'5', {"jkl"}},
        {'6', {"mno"}},
        {'7', {"pqrs"}},
        {'8', {"tuv"}},
        {'9', {"wxyz"}},
    };

    std::string temp;
    std::vector<std::string> result;
    void dfs(int i, const std::string& digits) {
        if (temp.size() == digits.size()) result.push_back(temp);
        else {
            for (auto ch : mp[digits[i]]) {
                temp.push_back(ch);
                dfs(i + 1, digits);
                temp.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0) 
            dfs(0, digits);
        return result;
    }
};