class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::ranges::sort(pairs);

        int n = pairs.size();
        std::vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                auto end_first = pairs[j][1];
                auto start_second = pairs[i][0];
                if (end_first < start_second) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return *std::ranges::max_element(dp);
    }
};