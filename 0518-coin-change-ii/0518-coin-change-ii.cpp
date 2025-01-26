class Solution {
    std::vector<int> coins;
    std::vector<std::vector<int>> memo;
public:
    int change(int amount, vector<int>& coins) {
                this->coins = coins;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return number_of_ways(0, amount);
    }

    int number_of_ways(int i, int amount) {
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;
        if (memo[i][amount] != -1) return memo[i][amount];
        if (coins[i] > amount) {
            return memo[i][amount] = number_of_ways(i+1, amount);
        }
        memo[i][amount] = number_of_ways(i, amount - coins[i]) + number_of_ways(i + 1, amount);
        return memo[i][amount];
    }
};