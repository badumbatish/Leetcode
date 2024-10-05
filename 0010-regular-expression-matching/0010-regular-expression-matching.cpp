class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;

        for (j = 0; j < p.size(); j++) {
            if (p[j] != '.' && p[j] != '*') {
                if (p[j] == s[i]) {
                    i++;
                    continue;
                } else if (j + 1< p.size() && p[j+1] == '*'){
                    continue; 
                } else {
                    return false;
                }
            } else if (p[j] == '.') {
                if (j+1 < p.size() && p[j+1] != '.' && p[j+1] != '*') {
                    i++;
                    continue;
                }

                if (j+1 < p.size() && p[j+1] == '.') {
                    i++;
                    continue;
                }

                if (j+1 < p.size() && p[j+1] == '*') {
                    continue;
                }

                i++;
            } else if (p[j] == '*') {
                if (p[j-1] == '.') {
                    if (j + 1 < p.size()) {
                        while (i < s.size() && s[i] != p[j+1]) {
                            i++;
                        }
                    } else {
                        return true;
                    }
                } else {
                    if (j + 1 < p.size() && p[j-1] == p[j+1]) {
                        while (i+1 < s.size() && s[i] == p[j-1]) {
                            i++;
                        }
                    } else {
                        while (i < s.size() && s[i] == p[j-1]) {
                            i++;
                        }
                    }

                }
            }
        }

        std::cout << "i : " << i << " - " << s.size() << std::endl;
        std::cout << "j : " << j << " - " << p.size() << std::endl;
        return i == s.size() && j == p.size();
    }
};