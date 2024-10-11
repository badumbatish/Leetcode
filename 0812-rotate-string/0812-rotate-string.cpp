class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        // Find first char of s in goal = j
        
        // From n = 0 to s.len(), iterate and check if s[i + n] = goal[j + n]

        char ch = s[0];
        auto first_found = std::find(goal.begin(), goal.end(), ch);
        if (first_found == goal.end()) return false;

        int base_index = first_found - goal.begin();

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[(i + base_index) % s.size()]) return false;
        } 
        return true;
    }
};