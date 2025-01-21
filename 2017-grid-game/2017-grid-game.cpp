#include <ranges>
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int64_t first_row_sum = std::ranges::fold_left(grid[0], (int64_t)0, std::plus<>());
        int64_t min_sum = std::numeric_limits<int64_t>::max();
        int64_t second_row_sum = 0;

        for (int i = 0; i < grid[0].size(); i++) {
            first_row_sum -= grid[0][i];
            min_sum = std::min(min_sum, std::max(first_row_sum, second_row_sum));
            second_row_sum += grid[1][i];
        }
        return min_sum;
    }
};