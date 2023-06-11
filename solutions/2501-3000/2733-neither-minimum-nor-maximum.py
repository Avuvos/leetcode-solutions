class Solution:
    def findNonMinOrMax(self, nums: List[int]) -> int:
        mn = min(nums)
        mx = max(nums)
        for x in nums:
            if x != mn and x != mx:
                return x
        return -1
