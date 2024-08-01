class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left, right;
        std::unordered_map<char, int> mp;

        int max_count = 0;
        for (left = 0, right = 0; right < s.size(); right++) {
            mp[s[right]]++;

            while (mp.size() > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            max_count = max(max_count, right - left + 1);
            
        }

        return max_count;
    }
};