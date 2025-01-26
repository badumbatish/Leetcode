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

        if (ump[rem] != 0) return ump[rem];
        
        int mini = INT_MAX;
        for (auto coin : coins) {
            int res = memo(coins, rem - coin);
            if (res >= 0 && res < mini) {
                mini = 1 + res;
            }
        }

        ump[rem] = (mini == INT_MAX) ? - 1 : mini;

        return ump[rem];
    }
};