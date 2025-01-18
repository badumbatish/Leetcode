class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int left = 0; left < haystack.size(); left++) {
            bool found = true;
            for (int right = 0; right < needle.size(); right++) {
                if (needle[right] == haystack[left + right]) continue;
                else {
                    found = false;
                    break;
                }
            }
            if (found) return left;

        } 
        return -1;
    }
};