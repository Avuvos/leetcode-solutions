class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        @cache
        def dfs(x, y, cnt):
            if x >= m or x < 0 or y >= n or y < 0:
                return False
            if grid[x][y] == ")" and cnt <= 0:
                return False
            if grid[x][y] == "(":
                cnt += 1
            else:
                cnt -= 1
            if x == m - 1 and y == n - 1 and cnt == 0:
                return True
            
            l = dfs(x + 1, y, cnt)
            d = dfs(x, y + 1, cnt)
            return l or d
        return dfs(0, 0, 0)
