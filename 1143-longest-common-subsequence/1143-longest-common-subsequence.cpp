class Solution {
public:
int longestCommonSubsequence(string &a, string &b) {
    short m[1001][1001] = {};
    for (auto i = 1; i <= a.size(); ++i)
        for (auto j = 1; j <= b.size(); ++j)
        // if current one are equal, then we accept both char at each string, this forms the base for the next chars
        // else we need to consider 
            m[i][j] = a[i-1] == b[j-1] ? m[i-1][j-1] + 1 : max(m[i][j-1], m[i-1][j]);
    return m[a.size()][b.size()];

    /*
          012345
        0|000
        1| 1
        2
        3
        4


    */
}
};