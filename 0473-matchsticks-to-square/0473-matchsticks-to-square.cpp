class Solution {
    std::vector<int> sums = std::vector<int>(4, 0);
    int square_length = 0;
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 3) return false;

        
        int64_t perimeter = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        square_length = perimeter / 4;
        if (square_length * 4 != perimeter) return false;


        std::sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, 0);

    }

    bool dfs(std::vector<int> &matchsticks, int start) {
        if (start == matchsticks.size()) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }

        int elem = matchsticks[start];

        for (int i = 0; i < 4; i++) {
            if (sums[i] + elem <= square_length) {
                sums[i] += elem;
                if (dfs(matchsticks, start + 1)) return true;

                sums[i] -= elem;
            }
        }

        return false;
    }
};