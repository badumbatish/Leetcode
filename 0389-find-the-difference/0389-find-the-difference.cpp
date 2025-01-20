class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> mp;
        for (auto ch : s) mp[ch]++;
        for (auto ch : t) {
            if (!mp.contains(ch)) return ch;
            mp[ch]--;
            if (mp[ch] == 0) mp.erase(ch);
        }
        return 'x';
    }
};