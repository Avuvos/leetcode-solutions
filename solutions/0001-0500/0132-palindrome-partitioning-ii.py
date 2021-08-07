class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        
        if s==s[::-1]:
            return 0
        
        cuts = [i for i in range(-1, n)]
        
        for i in range(0, n):
            for j in range(i, n):
                if s[i:j] == s[j:i:-1]:
                    cuts[j+1] = min(cuts[j+1], cuts[i]+1)
        return cuts[-1]
