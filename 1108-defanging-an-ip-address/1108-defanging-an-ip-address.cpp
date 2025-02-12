class Solution {
public:
    string defangIPaddr(string address) {
        std::string result;
        for (auto ch : address) {
            if (ch == '.') result.push_back('[');
            result.push_back(ch);
            if (ch == '.') result.push_back(']');
        }
        return result;
    }
};