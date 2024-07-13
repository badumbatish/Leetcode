class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        int count = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                if (is_substring_palindrome(s, i, j-1) || is_substring_palindrome(s, i+1, j)) {
                    return true;
                } else {
                    return false;
                }
            }
            i++;
            j--;
        }

        return true;
    }

    bool is_substring_palindrome(const std::string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};