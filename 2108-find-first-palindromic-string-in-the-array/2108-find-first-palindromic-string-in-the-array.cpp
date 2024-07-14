class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &str : words) {
            if (balindrome(str)) return str;
        }
        return "";
    }

    bool balindrome(const std::string &str) {
        int i = 0;
        int j = str.size() - 1;

        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};