class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        std::nth_element(prices.begin(), prices.begin() + 2, prices.end());

        int buy = prices[0] + prices[1];
        
        if (buy > money) return money;
        return money - buy;
    }
};