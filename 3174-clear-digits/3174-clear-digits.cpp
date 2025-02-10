class Solution {
public:
    string clearDigits(string s) {
        std::deque<char> st;
        for (auto ch : s) {
            if (isdigit(ch)) st.pop_back();
            else st.push_back(ch);
        }
        std::string str;
        for (auto ch : st) str.push_back(ch);

        return str;
    }
};