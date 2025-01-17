class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for (auto ch : s) {
            if (ch == '[' || ch == '(' || ch == '{'){
                st.push(ch);
            } else {
                if (st.empty()) return false;
                if (st.top() == '[' && ch == ']') st.pop();
                else if (st.top() == '{' && ch == '}') st.pop();
                else if (st.top() == '(' && ch == ')') st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};