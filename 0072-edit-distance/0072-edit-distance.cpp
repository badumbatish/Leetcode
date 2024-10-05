class Solution {
    
public:
using Cache =std::vector<std::vector<int>> ;
    int minDistance(string word1, string word2) {

        int m = word1.size(), n = word2.size();
        
        Cache cache(m + n, std::vector<int>(m+n, INT_MAX));
        return recurse(0, word1, 0, word2, cache);
    }

    int recurse(int i, std::string& word1, int j, const std::string& word2, Cache& cache) {
        if (i >= word1.size() && j >= word2.size()) return 0;
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;

        if (word1[i] == word2[j]) {
            cache[i][j] = recurse(i+1, word1, j+1, word2, cache);
            return cache[i][j];
        }
        else {
// SCE A
            if (cache[i][j+1] == INT_MAX) {
                cache[i][j+1]= recurse(i, word1, j+1, word2, cache);
            }

            if (cache[i+1][j] == INT_MAX) {
                cache[i+1][j]= recurse(i+1, word1, j, word2, cache);

            }
            if (cache[i+1][j+1] == INT_MAX) {
                cache[i+1][j+1]= recurse(i+1, word1, j+1, word2,cache);
            }

            if (cache[i][j] == INT_MAX) {
                cache[i][j] = 1 + min(cache[i][j+1], std::min(cache[i+1][j], cache[i+1][j+1]));
            }
            return cache[i][j];
        } 
        // 0 0
        // rose
        // 0123
        // arose.  ose   aose
        // 01234.  012   0123

        // abcd.   abcd  abcd
        // 0123.   0123. 0123

        // 
    }
};