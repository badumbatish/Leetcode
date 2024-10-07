class Solution {
public:
    int minLength(string s) {
        std::string stck;

        for (int i = 0; i < s.size() ; i++) {
            stck.push_back(s[i]);

            while (stck.ends_with("AB") || stck.ends_with("CD"))  {
                stck.pop_back(); stck.pop_back();

            }
        }

        return stck.size();
    }
};