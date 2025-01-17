#include <ranges>
class UF {
    std::vector<int> v;
    std::vector<int> rank;
    int count = 0;
    public:
    UF(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                }
                v.push_back(i * n + j);
                rank.push_back(0);
            }
        }
        assert(v.size() == grid.size() * grid[0].size());
    }
    int find(int i) {
        if (v[i] != i) v[i] = find(v[i]);
        return v[i];
    }
    void connect(int a, int b) {
        auto fa = find(a), fb = find(b);
        if (fa == fb) return;
        if (rank[fa] > rank[fb])
            v[fb] = fa;
        else {
            v[fa] = fb;
            if (rank[fa] == rank[fb]) rank[fb] = rank[fb] + 1;
        }
        count--;
        std::cout << count << std::endl;
    }
    int size() {
        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        static std::array<int, 5> dir = {-1, 0, 1, 0, -1};
        auto is_within = [&](auto a, auto b) { return 0 <= a && a < grid.size() && 0 <= b && b < grid[0].size(); };
        UF uf(grid);
int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {  // Only process land cells
                    for (int d = 0; d < 4; d++) {
                        int x = i + dir[d], y = j + dir[d + 1];
                        if (is_within(x, y) && grid[x][y] == '1') {
                            uf.connect(i * n + j, x * n + y);  // FIXED: Correct indexing
                        }
                    }
                }
            }
        }
        return uf.size();
    }
};