class Solution {
public:
    int longestRepeatingSubstring(string s) {
        std::unordered_set<std::string> seen_substrings;
        int max_length  = s.length();

        for (int start =  0;start <= s.length();start++) {
            int end = start;

            if (end + max_length > s.length()) {
                if (--max_length == 0) break;

                start = -1;
                seen_substrings.clear();
                continue;
            }
            std::string current_substring = s.substr(end, max_length);


            if (!seen_substrings.insert(current_substring).second) {
                return max_length;
            }
        }

        return max_length;
    }
};