class Solution:
    def sumOfPower(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        MOD = 10**9 + 7
        n = len(nums)
        for i in range(n):
            ans += nums[i] * nums[i] * nums[i]
            ans %= MOD
        s = 0
        for i in range(n - 2, -1, -1):
            mn = nums[i]
            s += nums[i + 1] * nums[i + 1]
            ans += mn * s
            ans %= MOD
            s *= 2
            s %= MOD
        return ans
        
        
        
        
        
