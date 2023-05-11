class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)
        @cache
        def dfs(top, bot):
            if top >= n or bot >= m:
                return 0
            take = skip1 = skip2 = 0
            if nums1[top] == nums2[bot]:
                take = 1 + dfs(top + 1, bot + 1)
            skip1 = dfs(top + 1, bot)
            skip2 = dfs(top, bot + 1)
            return max(take, skip1, skip2)
        return dfs(0, 0)
