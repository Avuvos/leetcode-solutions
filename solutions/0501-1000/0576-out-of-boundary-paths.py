class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        @cache
        def dfs(x, y, turn):
            if x < 0 or y < 0 or x >= m or y >= n:
                return 1
            if turn >= maxMove:
                return 0
            left = dfs(x + 1, y, turn + 1)
            right = dfs(x - 1, y , turn + 1)
            down = dfs(x, y + 1, turn + 1)
            up = dfs(x, y - 1, turn + 1)
            return (left + right + down + up) % (10**9 + 7)
        return dfs(startRow, startColumn, 0)
