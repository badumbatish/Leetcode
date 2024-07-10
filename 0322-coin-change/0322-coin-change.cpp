class Solution {
public:
    std::unordered_map<int, int> ump;
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return 0;
        return memo(coins, amount);
    }

    int memo(std::vector<int>&coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;

        if (ump[rem-1] != 0) return ump[rem-1];
        
        int mini = INT_MAX;
        for (auto coin : coins) {
            int res = memo(coins, rem - coin);
            if (res >= 0 && res < mini) {
                mini = 1 + res;
            }
        }

        ump[rem-1] = (mini == INT_MAX) ? - 1 : mini;

        return ump[rem-1];
    }
};