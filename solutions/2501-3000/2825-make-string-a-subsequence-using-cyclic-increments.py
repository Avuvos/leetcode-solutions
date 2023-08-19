class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        
        @cache
        def dfs(i, j):
            if j >= len(str2):
                return True
            if i >= len(str1):
                return False
            if str1[i] == str2[j]:
                return dfs(i + 1, j + 1)
            c = chr(ord(str1[i]) + 1)
            if ord(c) > ord('z'):
                c = 'a'
            if c == str2[j]:
                return dfs(i + 1, j + 1)
            return dfs(i + 1, j)
        
        return dfs(0, 0)
