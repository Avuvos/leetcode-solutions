class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curr = res = nums[0]
        for i in range(1, len(nums)):
            curr = max(curr + nums[i], nums[i])
            res = max(res, curr)
        return res
            
