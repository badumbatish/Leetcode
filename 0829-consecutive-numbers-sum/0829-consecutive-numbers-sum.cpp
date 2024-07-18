class Solution {
public:
    int consecutiveNumbersSum(int n) {
       int count = 1;

       for (int k = 2; k < sqrt(2 * n); k++) {
            auto potential_multiple_k = n - (k * (k - 1) / 2);
            if (potential_multiple_k % k == 0) count++;
       } 

       return count;
    }
};