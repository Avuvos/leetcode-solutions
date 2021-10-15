class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        
        #isomorphism means we can match char from s to t and the opposite
        ds = {} 
        dt = {} 
        
        for i in range(len(s)):
            if s[i] in ds and ds[s[i]] != t[i]:
                return False
            if t[i] in dt and dt[t[i]] != s[i]:
                return False
            ds[s[i]] = t[i]
            dt[t[i]] = s[i]
        
        return True
