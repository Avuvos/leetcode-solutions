class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for h, w, p in prices:
            dp[h][w] = p
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                for a in range(1, i//2 + 1):
                    dp[i][j] = max(dp[i][j], dp[a][j] + dp[i - a][j])
                for a in range(1, j//2 + 1):
                    dp[i][j] = max(dp[i][j], dp[i][a] + dp[i][j - a])
        return dp[m][n]
