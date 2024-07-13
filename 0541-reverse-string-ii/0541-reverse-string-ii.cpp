class Solution {
public:
    string reverseStr(string s, int k) {
        for (int start = 0; start < s.size(); start += 2 *k) {
            int i = start, j = std::min(start + k - 1, (int)s.size() - 1);

            while (i < j) {
                std::swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;

    }

};