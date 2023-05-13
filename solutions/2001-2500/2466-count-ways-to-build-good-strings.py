class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        cnt = [0] * (high + 1)
        cnt[0] = 1
        MOD = 10**9 + 7
        ans = 0
        for i in range(high + 1):
            if i - one >= 0:
                cnt[i] += cnt[i - one]
            if i - zero >= 0:
                cnt[i] += cnt[i - zero]
            cnt[i] %= MOD
            if i >= low and i <= high:
                ans += cnt[i]
                ans %= MOD
                
        return ans % MOD
