class Solution:
    def numTrees(self, n: int) -> int:
        
        '''
        @cache
        def dfs(s, e):
            if s >= e:
                return 1
            res = 0
            for idx in range(s, e + 1):
                left = dfs(s, idx - 1)
                right = dfs(idx + 1, e)
                res += left * right
            return res
        return dfs(1, n)
        '''
        
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1 #base case
        
        for i in range(2, n + 1): #calc dp[i]
            for r in range(1, i + 1): #any of 1,..i can be the root
                dp[i] += dp[r - 1] * dp[i - r]
        return dp[n]
        
