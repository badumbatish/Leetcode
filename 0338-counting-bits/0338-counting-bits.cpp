class Solution {
public:
    vector<int> countBits(int n) {
        // n = 0 => 0
        // n = 1 => 1
        // n = 2 => 1
        std::vector<int> result;

        for (int i = 0; i <= n; i++) {
            result.push_back(hammingWeight(i));
        }

        return result;
    }

    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            count += (n % 2);
            n /= 2;
        }

        return count;
    }
};