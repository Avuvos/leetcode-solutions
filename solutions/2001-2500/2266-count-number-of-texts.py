class Solution:
    def countTexts(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1
        MOD = 10**9 + 7
        
        for i in range(2, n + 1):
            dp[i] += dp[i - 1]
            c = s[i - 1]
            if c == s[i - 2]:
                dp[i] += dp[i - 2]
                if i >= 3 and c == s[i - 3]:
                    dp[i] += dp[i - 3]
                    if i >= 4 and (c == '7' or c == '9') and c == s[i - 4]:
                        dp[i] += dp[i - 4]
            dp[i] = dp[i] % MOD
        
        return dp[n]
