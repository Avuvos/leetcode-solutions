class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        n = len(special)
        special.sort()
        res = special[0] - bottom
        for i in range(1, n):
            cur = special[i] - special[i - 1] - 1
            res = max(res, cur)
        res = max(res, top - special[n - 1])
        return res
