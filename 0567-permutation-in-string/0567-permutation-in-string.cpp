class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        std::map<char, int> map_1;
        for (auto ch : s1) map_1[ch]++;

        for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
            std::map<char, int> map_2;

            for (int j = 0; j < s1.size(); j++) {
                map_2[s2[i+j]]++;
            }
            if (matches(map_1, map_2)) return true;
        }

        return false;
    }

    bool matches(std::map<char, int> &a, std::map<char, int>&b) {
        for (auto [key, value] : a) {
            if (a[key] - b[key] != 0) return false;
        }

        return true;
    }


};