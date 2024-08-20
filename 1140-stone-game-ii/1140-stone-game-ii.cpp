class Solution {
    std::vector<std::vector<int>> memo;
    std::vector<int> suffix_sum;
public:
    int stoneGameII(vector<int>& piles) {
        memo = std::vector<std::vector<int>>(piles.size(), std::vector<int>(piles.size(), 0));
        suffix_sum = piles;
        for (int i = suffix_sum.size() - 2; i >= 0; i--) 
            suffix_sum[i] += suffix_sum[i + 1];
        
        return max_stones(1, 0);
    }

    int max_stones(int M, int current_index) {
        if (current_index + 2 * M >= suffix_sum.size()) return suffix_sum[current_index];
        if (memo[current_index][M] > 0) return memo[current_index][M];

        int res = INT_MAX;

        for (int i = 1; i <= 2 * M; i++) {
            // We check for the next turn, where Bob is playing,
            // after Alice has picked either 1 stone or up to 2 * M stones. 
            res = std::min(res, max_stones(max(i, M), current_index + i));
        }

        memo[current_index][M] = suffix_sum[current_index] - res;
        return memo[current_index][M];
    }
};