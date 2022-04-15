class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        best_max = cur_max = nums[0]
        best_min = cur_min = nums[0]
        s = sum(nums)
        for i in range(1, n):
            cur_max = max(cur_max + nums[i], nums[i])
            best_max = max(best_max, cur_max)
            cur_min = min(cur_min + nums[i], nums[i])
            best_min = min(best_min, cur_min)
            
        return max(best_max, s - best_min) if s - best_min > 0 else best_max
