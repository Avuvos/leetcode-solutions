class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        ones = [-1] + [i for i, x in enumerate(nums) if x % 2 == 1] + [len(nums)]
        ans = 0
        for i in range(k, len(ones) - 1):
            right = ones[i + 1] - ones[i]
            left = ones[i - (k - 1)] - ones[i - (k - 1) - 1]
            ans += left * right
        return ans
