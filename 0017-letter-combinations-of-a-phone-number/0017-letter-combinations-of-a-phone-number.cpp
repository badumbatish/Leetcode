class Solution {
    std::map<int, std::string> digits_map = {
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    int length;
    std::vector<std::string> result;
    std::string temp;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        length = digits.size();
        dfs(digits, 0);

        return result;
    }

    void dfs(std::string& digits, int start) {
        if (temp.size() == length) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < digits_map[digits[start] - '0'].size(); i++) {
            temp.push_back(digits_map[digits[start] - '0'][i]);
            dfs(digits, start + 1);
            temp.pop_back();
        }
    }
};
