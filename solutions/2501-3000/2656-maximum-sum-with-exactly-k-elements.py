class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        ans = 0
        while k:
            ans += mx
            mx += 1
            k -= 1
        return ans
