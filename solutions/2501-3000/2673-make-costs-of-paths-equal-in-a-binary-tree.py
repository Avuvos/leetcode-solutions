class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        def maxCost(x):
            nonlocal ans
            if x > n: return 0
            left = maxCost(2*x)
            right = maxCost(2*x + 1)
            ans += abs(right - left)
            return cost[x - 1] + max(left, right)
        maxCost(1)
        return ans
        
