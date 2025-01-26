class Solution {
    std::vector<std::vector<int>> memo;
    std::string s;
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        this->s = s;
        memo = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        return lps(0, n-1);
    }

    int lps(int i, int j) {
        if (memo[i][j] != 0) return memo[i][j];
        if (i > j) return 0;
        if (i == j) return 1;

        if (s[i] == s[j])
            memo[i][j] = lps(i + 1, j - 1) +2;
        else  
            memo[i][j] = std::max(lps(i+1, j), lps(i, j-1));
        
        return memo[i][j];
    }
};