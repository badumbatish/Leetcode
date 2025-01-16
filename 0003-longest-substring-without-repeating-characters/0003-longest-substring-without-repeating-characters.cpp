#include <ranges>
using namespace ranges;
using namespace views;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t max_length = 0;
        std::unordered_map<char, int> last_seen_map;
        size_t start = 0;
        for (auto [end, ch] : enumerate(s)) {
            if (last_seen_map[ch] > 0) start = std::max((size_t)last_seen_map[ch], (size_t)start);
            max_length = std::max(max_length, end - start + 1);
            last_seen_map[ch] = end + 1;
        }
        return max_length;
    }
};