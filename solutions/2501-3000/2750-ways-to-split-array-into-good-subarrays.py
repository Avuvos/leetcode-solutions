class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        ans = 1
        MOD = 10**9 + 7
        ones = [i for i, x in enumerate(nums) if x == 1]
        if not ones:
            return 0
        for i in range(len(ones) - 1):
            ans *= (ones[i + 1] - ones[i])
            ans %= MOD
        return ans
