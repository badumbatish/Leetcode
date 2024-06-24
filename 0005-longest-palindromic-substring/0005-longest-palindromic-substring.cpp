class Solution {
public:
    std::string_view expand(int i, int j, std::string_view s) {
        // Starting from i and j, we go out both directions 
        // until either s[i] != s[j]
        // or they went out of the bound of the string view

        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }

        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        std::string_view ans = "";

        for (int i = 0 ; i < s.size(); i++) {
            auto odd = expand(i, i , s);
            if (odd.size() > ans.size()) ans = odd;

            auto even = expand(i, i + 1, s);
            if (even.size() > ans.size()) ans = even;

        }
        return std::string(ans);
    }
};