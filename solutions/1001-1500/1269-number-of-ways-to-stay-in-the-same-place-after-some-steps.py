class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10**9 + 7
        
        @cache
        def dfs(pos, left):
            if pos >= arrLen or pos < 0:
                return 0
            if left == 0:
                return 1 if pos == 0 else 0 
            ans = dfs(pos + 1, left - 1) % MOD
            ans += dfs(pos - 1, left - 1) % MOD
            ans += dfs(pos, left - 1) % MOD
            return ans % MOD
        
        return dfs(0, steps)
