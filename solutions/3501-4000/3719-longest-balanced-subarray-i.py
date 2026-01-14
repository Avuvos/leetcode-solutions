class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for l in range(n):
            de, do = set(), set()
            for r in range(l, n):
                if nums[r] % 2 == 0:
                    de.add(nums[r])
                else:
                    do.add(nums[r])
                if len(de) == len(do):
                    ans = max(ans, r - l + 1)
        return ans
