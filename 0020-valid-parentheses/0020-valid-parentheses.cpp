class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stck;

        for (auto it = s.begin(); it != s.end(); it++) {
            if (*it == '(' || *it == '{' || *it == '[' ) {
                stck.push(*it);
            } else {
                if (stck.empty()) return false;

                auto match = stck.top();
                stck.pop();

                if (match == '[' && *it == ']') continue;
                if (match == '(' && *it == ')') continue;
                if (match == '{' && *it == '}') continue;

                return false;
            }
        }

        return stck.empty();
    }
};