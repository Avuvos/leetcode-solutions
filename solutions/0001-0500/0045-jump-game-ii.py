class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0 or n == 1: return 0
        dp = [float('inf')] * n
        dp[0], dp[1] = 0, 1
        for i in range(2, n):
            for j in range(i):
                if nums[j] + j >= i:
                    dp[i] = dp[j] + 1
                    break
        return dp[n - 1]
        
