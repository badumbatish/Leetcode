class Solution {
public:
    string longestPalindrome(string s) {
        for (int length = s.size() - 1 ; length >= 0; length--) {
            for (size_t start = 0; start <= s.size() - length; start++) {
                if (check(s, start, start + length )) {
                    return s.substr(start, length + 1);
                }
            }
        }
        return "";
    }

    bool check(std::string &s, int i, int j)
    {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};