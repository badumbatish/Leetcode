class Solution {
    std::string_view expand(int i, int j, std::string_view s) {
        int left = i, right = j;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {
        std::string_view ans = "";
        for (int i = 0; i < s.size(); i++) {
            auto odd = expand(i, i, s);
            if (odd.size() > ans.size()) ans = odd;
            auto even = expand(i, i+1, s);
            if (even.size() > ans.size()) ans = even;
        }
        return std::string(ans);
    }
};