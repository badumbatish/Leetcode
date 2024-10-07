class Solution {
    using Cache = std::vector<std::vector<int>>;
public:

    int minDistance(string word1, string word2) {
        auto m = word1.size(), n = word2.size();
        Cache cache = Cache(m+1, std::vector<int>(n+1));
        for (int i = 0; i <= m; i++) cache[i][0] = i; // Inserting all characters into words
        for (int j = 0; j <= n; j++) cache[0][j] = j; // Inserting all characters into words

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) cache[i][j] = cache[i-1][j-1];
                else {
                    cache[i][j] = 1 + min({cache[i-1][j-1], cache[i-1][j], cache[i][j-1]});
                }
            }
        }
        return cache[m][n];
    }
};