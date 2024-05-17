class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stck;

        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stck.push(ch);
            } else {
                if (stck.empty()) return false;

                auto match = stck.top();
                stck.pop();
                if (ch - match <= 2) continue;

                else return false;
            }
        }

        return stck.empty();
    }
};