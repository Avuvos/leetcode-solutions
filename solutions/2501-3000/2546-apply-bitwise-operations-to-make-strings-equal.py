class Solution:
    def makeStringsEqual(self, s: str, target: str) -> bool:
        if '1' not in target and '1' in s:
            return False
        
        if '1' not in s and '1' in target:
            return False
        
        return True
