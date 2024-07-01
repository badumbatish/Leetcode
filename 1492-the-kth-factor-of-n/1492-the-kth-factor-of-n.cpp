class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;

        int factor = 0;
        for (int i = 1; i <= n; i++) {
            if ( n % i == 0) count++;
            if (count == k) factor = i;
        }

        if (count < k) return -1;
        return factor;
        
    }
};