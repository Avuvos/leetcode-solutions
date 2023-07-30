class Solution:
    def strangePrinter(self, s: str) -> int:
        #observation: the operations are invertible
        #lets try to make s empty instead
        #imagine we keep the last char seen
        #so if our current char is equal, we simply continue
        #collecting that char
        #otherwise its not equal
        #we have two choices
        #either delete the previous streak
        #or move on and delete the current streak
        #thats it, literally thats it.
        
        n = len(s)
        
        @cache
        def dfs(l, r):
            if l > r:
                return 0
            ans = 1 + dfs(l + 1, r)
            for i in range(l + 1, r + 1):
                if s[i] == s[l]:
                    ans = min(ans, dfs(l, i - 1) + dfs(i + 1, r))
            return ans
        
        return dfs(0, n - 1)
                
