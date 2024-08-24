class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        @lru_cache(None)
        def dp1(col : int, up : bool) -> int:
            if col == n - 1:
                return 0
            
            if up:
                return max(dp1(j, not up) + dp2(col + 1, up, 0 , j) for j in range(col + 1, n))
            else: 
                return max(dp1(j, not up) + dp2(col, up, n - 1, j - 1) for j in range(col + 1, n))

        @lru_cache(None)
        def dp2(col: int, up : bool, x : int, y : int) -> int:
            if x == n or x == -1:
                return 0
            if y == col:
                return dp2(col, up, x + 1, y) + grid[x][y] if up else 0
            if up:
                return max(dp2(col, up, x, y - 1), dp2(col, up, x + 1, y) + grid[x][y])
            else:
                return max(dp2(col, up, x, y - 1), dp2(col, up, x - 1, y) + grid[x][y])

        n = len(grid)
        return dp1(-1, False)