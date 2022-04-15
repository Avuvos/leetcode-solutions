class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        res = 0
        best_spot = values[0]
        for i in range(1, len(values)):
            res = max(res, best_spot + values[i] - i)
            best_spot = max(best_spot, values[i] + i)
        return res
