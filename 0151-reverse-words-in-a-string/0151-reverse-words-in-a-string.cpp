class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> vec;
        std::stringstream str(s);
        std::string word;

        while (str >> word) vec.push_back(word);

        std::ranges::reverse(vec);
        std::string res;
        for (const auto &it : vec) res += " " + it;
        res.erase(0, 1);

        return res;
    }
};