class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        med = nums[len(nums) // 2]
        ans = 0
        for i in range(len(nums)):
            ans += abs(med - nums[i])
        return ans
