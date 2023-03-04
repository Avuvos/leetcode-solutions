class Solution:
    def coloredCells(self, n: int) -> int:
        if n == 1: return 1
        dp = [0] * (n + 1)
        dp[1] = 1
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + 4*(i - 1)
        return dp[n]
