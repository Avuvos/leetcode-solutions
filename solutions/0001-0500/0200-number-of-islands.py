class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])

        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        def dfs(i, j):
            if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != '1':
                return
            grid[i][j] = '0'
            for di, dj in dirs:
                dfs(i + di, j + dj)

        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    dfs(i, j)
                    ans += 1

        return ans

