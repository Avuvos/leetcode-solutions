class Solution:
    def numOfWays(self, numbers: List[int]) -> int:
        MOD = 10**9 + 7
        def dfs(nums):
            if len(nums) <= 2:
                return 1
            big = [a for a in nums[1:] if a > nums[0]]
            small = [a for a in nums[1:] if a < nums[0]]
            return (comb(len(nums) - 1, len(small)) * dfs(big) * dfs(small)) % MOD
        return (dfs(numbers) - 1) % MOD
