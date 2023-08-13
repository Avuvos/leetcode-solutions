class Solution:
    def maxSum(self, nums: List[int]) -> int:
        ans = -1
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                s = str(nums[i])
                t = str(nums[j])
                if max([int(c) for c in s]) == max([int(c) for c in t]):
                    ans = max(ans, nums[i] + nums[j])
        return ans
                    
