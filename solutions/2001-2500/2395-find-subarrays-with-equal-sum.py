class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n - 1):
            s = nums[i] + nums[i + 1]
            for j in range(i + 1, n - 1):
                if s == nums[j] + nums[j + 1]:
                    return True
        return False
