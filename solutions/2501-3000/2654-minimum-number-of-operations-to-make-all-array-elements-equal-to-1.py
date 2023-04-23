class Solution:
    def minOperations(self, nums: List[int]) -> int:
        g = 0
        n = len(nums)
        for num in nums: g = gcd(g, num)
        if g > 1: return -1;
        ones = sum([num == 1 for num in nums])
        if ones > 0: return n - ones
        ans = 10**9
        for left in range(n):
            g = 0
            for right in range(left, n):
                g = gcd(g, nums[right])
                if g == 1:
                    ans = min(ans, right - left + n - 1)
        return ans
