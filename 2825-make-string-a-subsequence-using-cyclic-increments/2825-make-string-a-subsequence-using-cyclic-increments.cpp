class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            auto d = str2[j] - str1[i];
            if (d == 0 ||d == 1 || (str2[j] == 'a' && str1[i] == 'z')) {
                i++;
                j++;
            } else i++;
        }

        return j == str2.size();
    }
};