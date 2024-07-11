class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slow = 0, fast = 0;

        while (slow < s.size() && fast < t.size()) {
            if (s[slow] != t[fast]) {
                fast++;
            } else {
                slow++;
                fast++;
            }
        }

        return slow == s.size();
    }
};