class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        
        @cache
        def dfs(i, j):
            if i >= len(s1) and j >= len(s2):
                return 0
            if i >= len(s1):
                return sum(ord(s2[k]) for k in range(j, len(s2)))
            if j >= len(s2):
                return sum(ord(s1[k]) for k in range(i, len(s1)))
            if s1[i] == s2[j]:
                return dfs(i + 1, j + 1)
            return min(ord(s1[i]) + dfs(i + 1, j), 
                       ord(s2[j]) + dfs(i, j + 1))
        
        return dfs(0, 0)
