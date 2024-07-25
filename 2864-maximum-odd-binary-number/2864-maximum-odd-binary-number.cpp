class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        std::ranges::sort(s);
        std::nth_element(s.begin(), s.begin() + s.size(), s.end() - 1, std::greater());

        return s;
    }
};