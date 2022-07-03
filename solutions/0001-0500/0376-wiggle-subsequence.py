class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        
        dp = [[0, 0] for _ in range(n)] #dp[i][j] ending at idx i and j sign
        dp[0][0] = dp[0][1] = 1  #0 means positive 1 means negative
        
        for i in range(1, n):
            sign = nums[i] - nums[i - 1]
            if sign == 0: 
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = dp[i - 1][1]
            elif sign > 0:
                dp[i][0] = 1 + dp[i - 1][1]
                dp[i][1] = dp[i - 1][1]
            else:
                dp[i][0] = dp[i - 1][0]
                dp[i][1] = 1 + dp[i - 1][0]
        return max(dp[-1][0], dp[-1][1])
