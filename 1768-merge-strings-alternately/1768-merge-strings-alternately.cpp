class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0, right = 0;
        int m = word1.size(), n = word2.size();

        std::string s;
        while (left < m && right < n) {
            s.push_back(word1[left++]);
            s.push_back(word2[right++]);
        }

        while (left < m) {
            s.push_back(word1[left++]);
        }
        while (right < n) {
            s.push_back(word2[right++]);
        }

        return s;
    }
};