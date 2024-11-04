class Solution {
public:
    string makeFancyString(string s) {
        std::string result_string;

        if (s.size() <= 2) return s;
        for (int i = 0; i < 2; i++) result_string += s[i];

        for (int i = 2; i < s.size(); i++) {
            char a = result_string[result_string.size() - 1];
            char b = result_string[result_string.size() - 2];

            if (a == b && a == s[i]) continue;
            result_string += s[i];
        }

        return result_string;
    }
};