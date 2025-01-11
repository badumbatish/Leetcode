class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        constexpr std::array<int,5> dir = {-1, 0, 1, 0, -1};

        int m = grid.size();
        int n = grid[0].size();

        std::queue<std::tuple<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ans = -1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [a, b] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int r = a + dir[i];
                    int c = b + dir[i+1];

                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    }
                }
            }

            ans++;
        }

        if (fresh > 0) return -1;
        if (ans == -1) return 0;

        return ans;
    }
};