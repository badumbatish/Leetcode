class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        std::string result = "";
        int i = 0, j = 0;
        
        while (i < m || j < n) 
        {
            if (i < m) {
                result += word1[i++];
            }
            if (j < n) {
                result += word2[j++];
            }
        }

        return result;
    }
};