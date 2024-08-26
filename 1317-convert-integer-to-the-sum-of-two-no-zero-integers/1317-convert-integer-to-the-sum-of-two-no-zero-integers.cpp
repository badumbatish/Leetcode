class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n / 2; i++) {
            if (!contains_zero(i) && !contains_zero(n - i)) return {i, n - i};
        }
        return {0 ,0};
    }

    bool contains_zero(int n) {
        while (n) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }
};