class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        m = len(nums[0])
        trimmed = []
        for offset in range(1, m + 1):
            cur = sorted([(num[m - offset:], index) for index, num in enumerate(nums)])
            trimmed.append(cur)
        ans = [trimmed[t - 1][k - 1][1] for k, t in queries]
        return ans


