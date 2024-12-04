class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        std::string result;
        int si = 0;

        for (int i = 0; i < s.size(); i++) {
            if (si < spaces.size() && i == spaces[si]) {
                result += ' ';
                si++;
            }
            result += s[i];
            
        } 
    return result;
    }
};