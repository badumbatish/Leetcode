class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // 7, 1, 5, 10, 3, 6, 4
       //    10 - 1 = 10 - 5 + 5 -1    

        // 7
        // 0
       int running_min = prices.front();
       int profit = 0;

       for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > running_min) {
                profit += (prices[i] - running_min);
                running_min = prices[i];
            } else {
               running_min = std::min(running_min, prices[i]);
            }
       }
       return profit;
    }
};