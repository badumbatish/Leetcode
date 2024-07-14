class Solution {
public:
    string removeStars(string s) {
       std::string result;

       for (auto ch : s) {
        if (ch != '*') result.push_back(ch);
        else {
            result.pop_back();
        }
       } 

       return result;
    }
};