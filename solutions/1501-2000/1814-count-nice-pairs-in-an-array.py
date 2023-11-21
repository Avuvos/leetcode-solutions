class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        mp = defaultdict(int)
        ans = 0
        for i, x in enumerate(nums):
            d = x - int(str(x)[::-1])
            ans += mp[d]
            mp[d] += 1
        return ans % MOD
