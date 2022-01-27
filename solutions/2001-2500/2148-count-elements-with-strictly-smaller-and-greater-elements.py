class Solution:
    def countElements(self, nums: List[int]) -> int:
        maxElem = max(nums)
        minElem = min(nums)
        res = 0
        for x in nums:
            if x > minElem and x < maxElem:
                res += 1
                
        return res
