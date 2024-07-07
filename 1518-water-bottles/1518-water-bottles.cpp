class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0;

        while (numBottles >= numExchange) {
            int prod = numBottles / numExchange;
            count += prod * numExchange;

            numBottles -= prod * numExchange;
            numBottles += prod;
        }

        //count += numBottles;

        return count + numBottles;
    }
};