class Solution {
    std::unordered_map<int, bool> memo;
    std::set<std::string> word_dict;
    std::string s;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->word_dict = std::set(wordDict.begin(), wordDict.end());
        return dp(s.length() - 1);
    }

    bool dp(int i) {
        if (i < 0) return true;

        if (memo.contains(i)) return memo[i];

        for (auto word : word_dict) {
            int size = word.size();

            if (i - size + 1 < 0) continue;

            if (s.substr(i - size + 1, size) == word && dp(i - size)) {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
};