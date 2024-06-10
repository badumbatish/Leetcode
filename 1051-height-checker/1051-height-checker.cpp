class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto expected = heights;
        std::ranges::sort(expected);
        int count = 0;
        for (int i = 0 ; i < expected.size(); i++) {
            count += (expected[i] != heights[i]);
        }

        return count;
    }
};