class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        std::string res;

        while (i < m || j < n) {
            if (i < m) res.push_back(word1[i++]);
            if (j < n) res.push_back(word2[j++]);
        }   
        return res;
    }
};