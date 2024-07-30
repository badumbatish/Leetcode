class Solution {
public:
    int minimumDeletions(string s) {
        std::stack<int> stck;
        int mini = 0;
        int b_count = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && b_count > 0) {
                mini++;
                b_count--;
            }
            if (s[i] == 'b') b_count++;
        }
        return mini;
    }
};