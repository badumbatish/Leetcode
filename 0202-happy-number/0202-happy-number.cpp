class Solution {
public:
    int get_sum_square_digits(int n) {
        int sum = 0;

        while (n) {
            sum += (n%10) * (n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::set<int> seen_before;

        while (true) {
            n = get_sum_square_digits(n);
            if (n == 1) return true;
            if (seen_before.count(n) == 1) return false;
            seen_before.insert(n);
        }
    }
};