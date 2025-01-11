class Solution {
    std::vector<int> dp = std::vector<int>(31, 0) ;
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] == 0)  {
            auto ans = fib(n-1) + fib(n-2);    
            dp[n] = ans;
            return ans;
        } else return dp[n];
    }
};