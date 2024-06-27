class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> n;
        n.push_back({1});
        for (int i = 1; i < numRows; i++) {
            n.push_back({});
            auto &v = n.back();
            v.push_back(1);
            for (int j = 1; j < i; j++) 
                v.push_back(n[i-1][j] + n[i-1][j-1]);
            v.push_back(1);
        }
        return n;
    }
};