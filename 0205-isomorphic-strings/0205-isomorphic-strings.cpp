#include <ranges>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> m1, m2;
        for (auto [ch1, ch2] : std::ranges::views::zip(s, t)) {
            if (!m1.contains(ch1))
                m1[ch1] = ch2;
            if (m1[ch1] != ch2) return false;

            if (!m2.contains(ch2))
                m2[ch2] = ch1;
            if (m2[ch2] != ch1) return false;
        }
        return true;
    }
};