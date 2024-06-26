class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> ump;
        for (char& ch : s) ump[ch]++;

        for (int i = 0; i < s.size(); i++) {
            if (ump[s[i]] == 1) return i;
        }
        return -1;
    }
};