class Solution {
    std::unordered_set<std::string> seen;
    int max_count = 0;
public:
    int maxUniqueSplit(string s) {
       backtrack(s, 0,0);
       return max_count;
    }

    void backtrack(const std::string& s, int current_count, size_t start) {

                // Prune: If the current count plus remaining characters can't exceed
        // maxCount, return
        if (current_count + (s.size() - start) <= max_count) return;
        if (start == s.size()) {
            max_count = max(max_count, current_count);
            return;
        }


        for (auto end = start + 1; end <= s.size(); end++) {
            std::string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);

                backtrack(s, current_count + 1, end);

                seen.erase(substring);
            }
        }

    }
};