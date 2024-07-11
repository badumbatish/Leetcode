class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;

        int k = s.size() - 1;
        while (s[k] == ' ') k--;
        
        for (int i = k; i >= 0; i--) {
            if (s[i] == ' ') break;
            else n++;
        }

        return n;
    }
};