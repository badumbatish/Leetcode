class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, std::string> map_char;
        std::map<std::string, char> map_str;

        std::vector<std::string> vstr;
        std::stringstream ss(s);

        while (ss) {
            std::string oh; ss >> oh;
            if (oh == "") break;
            vstr.push_back(oh);
        }
        

        if (pattern.size() != vstr.size()) return false;

        for (int i = 0; i < vstr.size(); i++) {
            char c = pattern[i];
            auto w = vstr[i];
            std::cout << w << std::endl;
            // If the current char is not registered yet but we already register for the word
            if (!map_char.contains(c)) {
                if (map_str.contains(w)) return false;
        

                map_char[c] = w;
                map_str[w] = c;
            } else {
                // Else if the char is register and it doesn't match
                std::string mapped_word = map_char[c];
                if (mapped_word != w) return false;
            }
        }

        return true;
    }
};