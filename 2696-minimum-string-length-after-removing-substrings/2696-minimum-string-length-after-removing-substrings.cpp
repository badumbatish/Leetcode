class Solution {
public:
    int minLength(string s) {
        std::string stck;

        for (int i = 0; i < s.size() ; i++) {
            stck.push_back(s[i]);
            if (stck.size() < 2) continue;

            while (stck.size() >= 2) {
                auto sub = stck.substr(stck.size() - 2, 2);
                if ( sub == "AB" || sub == "CD") {
                    stck.pop_back(); stck.pop_back();
                } else break;
            }
        }

        return stck.size();
    }
};