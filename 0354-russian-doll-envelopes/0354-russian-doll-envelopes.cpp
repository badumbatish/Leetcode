class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::ranges::sort(envelopes, [](auto &a, auto &b) {
            if (a[0] < b[0]) return true;
            else if (a[0] == b[0]) return a[1] > b[1];
            else return false;
        });
        int n = envelopes.size();
        std::vector<std::vector<int>> sub;
        
        sub.push_back(envelopes.front());
        auto less = [](auto& a, auto &b) {
            return a[0] < b[0] && a[1] < b[1];
        };

        for (int i = 1; i < n; i++) {
            auto doll = envelopes[i];
            if (less(sub.back(), doll)) {
                sub.push_back(doll);
            } else {
                int j = 0;
                while (less(sub[j] , doll)) j++;
                sub[j] = doll;
            }
        }
        return sub.size();
    }
};