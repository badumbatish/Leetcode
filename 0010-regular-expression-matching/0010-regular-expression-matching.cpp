class Solution {
public:
    bool isMatch(string s, string p) {
        // Memoization table to store results for each (i, j) pair
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return matchHelper(s, p, 0, 0, memo);
    }

private:
    bool matchHelper(const string &s, const string &p, int i, int j, vector<vector<int>> &memo) {
        // Check if we've already computed this subproblem
        if (memo[i][j] != -1) return memo[i][j];
        
        // Base case: if the pattern is exhausted, check if the string is also exhausted
        if (j == p.size()) {
            return memo[i][j] = (i == s.size());
        }

        // Check if the current character matches
        bool firstMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

        // If the next character is '*', we have two options:
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Case 1: Treat '*' as matching zero occurrences (skip current and next in pattern)
            // Case 2: Treat '*' as matching one or more occurrences (if firstMatch is true)
            memo[i][j] = (matchHelper(s, p, i, j + 2, memo) || (firstMatch && matchHelper(s, p, i + 1, j, memo)));
        } else {
            // No '*', so we must match the current character and move both pointers forward
            memo[i][j] = firstMatch && matchHelper(s, p, i + 1, j + 1, memo);
        }

        return memo[i][j];
    }
};
