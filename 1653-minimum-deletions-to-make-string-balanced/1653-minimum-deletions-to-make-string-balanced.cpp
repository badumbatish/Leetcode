class Solution {
public:
    int minimumDeletions(string s) {
        std::stack<int> stck;
        int mini = 0;
        for(int i = 0; i < s.size(); i++) {
            if (!stck.empty() && stck.top() > s[i]) {
                std::cout << i << std::endl;
                stck.pop();
                mini++;
            }
            if (s[i] == 'b') stck.push(s[i]);
        }

        return mini;
    }
};