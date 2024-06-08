class Solution {
public:
    vector<int> countBits(int n) {
        // n = 0 => 0
        // n = 1 => 1
        // n = 2 => 1
        std::vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; i++) {
            result.push_back(result[i >> 1] + (i & 1));
        }

        return result;
    }
};