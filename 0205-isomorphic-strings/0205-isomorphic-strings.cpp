#include <ranges>
class Solution {
    std::vector<int> transformed(const std::string & str) {
        std::unordered_map<char, int> i_map;
        std::vector<int> v;

        for (auto [i, ch] : std::ranges::views::enumerate(str)) {
            if (!i_map.contains(ch)) i_map[ch] = i;
            v.push_back(i_map[ch]);
        }
        return v;
    }
public:
    bool isIsomorphic(string s, string t) {
        return transformed(s) == transformed(t);
    }
};