class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums = sorted(nums, reverse=True)
        res = []
        for i in range(len(nums)):
            res.append(nums[0])
            nums.remove(nums[0])
            if sum(res) > sum(nums):
                return res
        return res
