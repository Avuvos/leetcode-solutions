class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        while n != 1:
            new = []
            for i in range(len(nums) - 1):
                new.append((nums[i] + nums[i + 1]) % 10)
            n = len(new)
            nums = new 
        return nums[0]
