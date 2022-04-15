class Solution:
    def getMaxLen(self, nums: List[int]) -> int:
        n = len(nums)
        res = neg = pos = 0
        
        for x in nums:
            if x > 0:
                pos, neg = pos + 1, neg + 1 if neg else 0
            elif x < 0:
                pos, neg = neg + 1 if neg else 0, pos + 1
            else:
                pos = neg = 0
            res = max(res, pos)
        return res
        
                
                
        
        
        
