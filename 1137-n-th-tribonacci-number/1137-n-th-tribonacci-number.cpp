class Solution {
public:
    int tribonacci(int n) {
        int zero = 0, one = 1, two = 1;
        if (n == 0) return 0;
        else if (n == 1 || n == 2) return 1;

        for (int i = 3; i <= n; i++) {
            int temp = zero + one + two;
            zero = one;
            one = two;
            two = temp;
        }
        return two;
    }
};