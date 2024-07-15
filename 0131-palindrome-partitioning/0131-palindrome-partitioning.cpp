class Solution {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> temp;
    
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);

        return result;
    }

    void dfs(std::string& s, int start) {
        if (start >= s.length()) result.push_back(temp);
        for (int end = start; end < s.length(); end++) {
            if (is_palindrome(s, start ,end)) {
                temp.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1);
                temp.pop_back();
            }
        }
    }

    bool is_palindrome(std::string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};