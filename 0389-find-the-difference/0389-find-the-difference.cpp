class Solution {
public:
    char findTheDifference(string s, string t) {
        char i = 0;
        for (auto ch : s) i^=ch;
        for (auto ch : t) i^=ch;
        return i;
    }
};