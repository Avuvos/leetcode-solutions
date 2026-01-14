class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        l = 0
        for r, x in enumerate(nums):
            while l < len(nums) and nums[l] != 0:
                l += 1
            if x != 0 and l < r:
                nums[l], nums[r] = nums[r], nums[l]
        return nums
        
