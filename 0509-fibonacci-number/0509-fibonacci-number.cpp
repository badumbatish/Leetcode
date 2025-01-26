class Solution {
public:
    int fib(int n) {
        int prev = 0, current = 1;
        if (n == 0) return 0;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            auto temp = current;
            current = current + prev;
            prev = temp ;
        }
        return current;
    }
};