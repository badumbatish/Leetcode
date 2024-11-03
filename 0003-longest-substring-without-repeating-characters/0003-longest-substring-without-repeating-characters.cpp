class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_map<char, int> freq_map;

        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.size()) {
            char ch_r = s[right];
            freq_map[ch_r]++;

            while (freq_map[ch_r] > 1) {
                char ch_l = s[left];
                freq_map[ch_l]--;
                left++;
            }
            max_len = max(max_len, right-left+1);
            right++; 
        }

        return max_len;
    }
};