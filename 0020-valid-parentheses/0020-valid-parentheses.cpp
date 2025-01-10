class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stck;

        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stck.push(ch);
                continue;
            } 
            if (stck.empty()) return false;

            auto match = stck.top();
            stck.pop();
            if (match == '[' && ch == ']') continue;
            if (match == '{' && ch == '}') continue;
            if (match == '(' && ch == ')') continue;

            return false;
            
        }

        return stck.empty();
    }
};