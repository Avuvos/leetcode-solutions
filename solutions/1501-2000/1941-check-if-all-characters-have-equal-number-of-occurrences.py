class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        
        n = len(s)
        d = {}
        
        for char in s:
            if char in d:
                d[char] += 1
            else:
                d[char] = 1
            amount = d[char]        
                
        for key in d:
            if d[key] != amount:
                return False
            
        return True
            
