class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        std::unordered_map<int, int> ump;

        int j = 0, i = 0;

        int res = 0;

        for (j = 0, i = 0; j < n; j++) {
            auto &m = ump[s[j]];
            if (m > 0) {
                i = max(m, i);
            }
            res = max(res, j - i + 1);
            m = j + 1;
        }

        return res;
    }
};