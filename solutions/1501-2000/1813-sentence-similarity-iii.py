class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        s1 = s1.split(" ")
        s2 = s2.split(" ")
        n = min(len(s1), len(s2))
        
        l = 0
        while l < n and s1[l] == s2[l]:
            l += 1
        
        r = 0
        while r < n and s1[-(r + 1)] == s2[-(r + 1)]:
            r += 1
        
        return l + r >= n
