class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [7,1,5,3,6,4]


        //  7  11 4 8 9 10
        //             rm 10, candidiate:0
        //        9    rm 10, c : 1
        //.     8.     rm 10  c : 2
        int running_max = prices.back();
        int candidate_profit = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            candidate_profit = std::max(candidate_profit, running_max - prices[i]);
            running_max = std::max(running_max, prices[i]);
        }
        return candidate_profit;
    }
};