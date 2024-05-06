class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() ==0 && t.size() == 0) return true;
        
        int fast = 0;
        int slow = 0;

        for (int fast = 0; fast < t.size() ; fast++) {
            if (t[fast] == s[slow]) {
                slow++;
            }

            if (slow == s.size()) {
                return true;
            }
        }

        return false;
    }
};