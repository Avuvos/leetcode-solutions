class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        
        
        def rec(nums, target, i, d):
            if i==len(nums):
                if target == 0:
                    return 1
                else:
                    return 0
            if (target,i) in d:
                return d[(target,i)]
            plus = rec(nums, target-nums[i], i+1, d)
            minus = rec(nums, target+nums[i], i+1, d)
            d[(target,i)] = plus + minus
            return d[(target,i)]
        
        return rec(nums, target, 0, {})
