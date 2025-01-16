class Solution {
public:
    int climbStairs(int n) {
        int first = 1, second = 2;
        int s = 2;
        if (n == 1) return 1;
        else if (n == 2) return 2;

        // 
        for (int i = 3; i <= n; i++) {
            s = first + second;
            first = second;
            second = s;
        } 
        return s;
    }
};