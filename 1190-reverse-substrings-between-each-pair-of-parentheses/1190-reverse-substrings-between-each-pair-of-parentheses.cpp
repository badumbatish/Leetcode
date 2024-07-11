class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<int> open_par_indices {};

        std::string result;

        for (auto ch : s) {
            if (ch == '(') {
                open_par_indices.push(result.length());
            } else if (ch == ')') {
                int start = open_par_indices.top();
                open_par_indices.pop();
                std::reverse(result.begin() +start, result.end());
            } else {
                result += ch;
            }
        }

        return result;
    }
};