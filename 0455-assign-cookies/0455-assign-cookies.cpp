class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size(), n = s.size();

        int i = 0;
        int j = 0;

        std::ranges::sort(g);
        std::ranges::sort(s);

        int count = 0;

        while (i < m && j < n) {
            if (g[i] <= s[j]) {
                count++;
                i++;
                j++;
            } else {
                break;
            }
        }

        return count;
    }
};