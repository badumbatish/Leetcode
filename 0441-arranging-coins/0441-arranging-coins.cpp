class Solution {
public:
    int arrangeCoins(int n) {
        int64_t left = 0, right = n;
        int64_t curr;

        while (left <= right) {
            int64_t mid = left + (right - left) / 2;
            curr = (mid * (mid + 1)) / 2;

            if (n == curr) {
                return mid;
            } else if (n < curr) right = mid - 1;
            else left = mid + 1;
        }

        return (int)right;
    }
};