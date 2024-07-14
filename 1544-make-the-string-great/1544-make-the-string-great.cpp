class Solution {
public:
    string makeGood(string s) {
        std::string str;

        for (auto ch : s) {
            if (str.size() != 0 && abs(str.back() - ch) == 32) str.pop_back();
            else str.push_back(ch);
        }

        return str;
    }
};