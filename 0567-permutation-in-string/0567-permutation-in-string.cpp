class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        std::ranges::sort(s1);
        for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
            auto sb = s2.substr(i, s1.size());
            std::ranges::sort(sb);

            if (sb == s1) return true;
        }

        return false;
    }
};