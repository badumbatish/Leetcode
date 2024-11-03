class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s.size() == 0) return false;


        for (int i = 0; i < s.size(); i++) {
            bool cont = true;
            for (int j = 0; j < s.size(); j++) {
                int index = (i + j) % s.size();
                if (s[index] != goal[j]) {
                    cont = false;
                    break;
                }
            }

            if (!cont) continue;
            else return true; 
        }


        return false;
    }
};