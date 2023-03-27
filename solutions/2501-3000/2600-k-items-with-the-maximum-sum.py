class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        d = min(numOnes, k)
        ans = d
        k -= d
        d = min(numZeros, k)
        k -= d
        d = min(numNegOnes, k)
        k -= d
        ans -= d
        return ans
