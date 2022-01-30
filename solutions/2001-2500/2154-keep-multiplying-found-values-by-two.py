class Solution:
    def findFinalValue(self, nums: List[int], x: int) -> int:
        nums = set(nums)
        
        while True:
            if x not in nums:
                return x
            x *= 2
        
        return x
        
