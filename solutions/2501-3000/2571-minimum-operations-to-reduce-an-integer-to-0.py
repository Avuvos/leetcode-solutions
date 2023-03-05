class Solution:
    def minOperations(self, n: int) -> int:
        
        @cache
        def dfs(x):
            if x <= 0: return 0
            if x == 1: return 1
            p = 1
            while 2 * p < x:
                p <<= 1
            return 1 + min(dfs(x - p), dfs(p*2 - x))
        
        return dfs(n)
