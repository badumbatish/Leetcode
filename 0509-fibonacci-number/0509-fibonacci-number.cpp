class Solution {
    std::vector<int> dp = std::vector<int>(31, 0) ;
public:
    Solution() {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= 30; i++) 
            dp[i] = dp[i-1] + dp[i-2];
    }
    int fib(int n) {
        int first = 0, second = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            auto temp = second;
            second = first + second;
            first = temp ;
        }
        return second;
    }
};