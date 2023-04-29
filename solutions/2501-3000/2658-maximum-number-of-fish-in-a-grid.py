class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        
        def dfs(x, y):
            if x >= n or x < 0 or y < 0 or y >= m:
                return 0
            if grid[x][y] == 0:
                return 0
            ans = grid[x][y]
            grid[x][y] = 0
            ans += dfs(x + 1, y)
            ans += dfs(x - 1, y)
            ans += dfs(x, y + 1)
            ans += dfs(x, y - 1)
            return ans
        
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] > 0:
                    res = max(res, dfs(i, j))
        return res
