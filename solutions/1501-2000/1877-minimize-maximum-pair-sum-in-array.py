class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        a = 0
        b = len(nums) - 1
        res = 0 
        while a < b:
            res = max(res, nums[a] + nums[b])
            a += 1
            b -= 1
        return res
