class Solution {
    std::unordered_set<std::string> seen;
public:
    int maxUniqueSplit(string s) {
       return backtrack(s, 0);
    }

    int backtrack(const std::string& s, size_t start) {
        if (start == s.size()) return 0;

        int max_count = 0;

        for (auto end = start + 1; end <= s.size(); end++) {
            std::string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);

                max_count = std::max(max_count,  1 + backtrack(s, end));

                seen.erase(substring);
            }
        }

        return max_count;
    }
};