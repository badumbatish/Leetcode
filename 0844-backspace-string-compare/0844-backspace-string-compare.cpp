class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    std::string build(std::string s) {
        std::string result;

        for (char ch : s) {
            if (ch != '#') result.push_back(ch);
            else if (!(result.size() == 0)) result.pop_back();
        }

        return result;
    }
};