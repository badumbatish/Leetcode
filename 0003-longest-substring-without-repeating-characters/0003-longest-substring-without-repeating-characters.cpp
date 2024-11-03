class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_map<char, int> freq_map;

        int left = 0, right = 0;

        int res = 0;

        while (right < s.size()) {
            char r = s[right];
            freq_map[r]++;

            while (freq_map[r] > 1) {
                char l = s[left];
                freq_map[l]--;
                left++;
            }

            res = std::max(res, right - left + 1);
            right++;
        }

        return res;
    }
};