#include <ranges>
using namespace ranges;
using namespace views;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t max_length = 0;
        for (auto [i, ch1] : enumerate(s)) {
            std::unordered_set<char> char_set;
            for (auto [j, ch2] : enumerate(s) | drop(i)) {
                char_set.insert(ch2);
                if (char_set.size() != (j-i+1)) break;
                max_length = std::max(max_length, (size_t)j-i+1);
            }
        }

        return max_length;
    }
};