class Solution {
public:
    bool rotateString(string s, string goal) {
        auto ss = s + s;
        return s.size() == goal.size() && ss.find(goal) != std::string::npos;
    }
};