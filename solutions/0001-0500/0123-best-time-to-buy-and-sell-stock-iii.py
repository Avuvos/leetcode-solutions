class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        @cache
        def dfs(idx, holding, left):
            if idx >= len(prices) or left <= 0:
                return 0
            buy = sell = 0
            if holding:
                sell = dfs(idx + 1, not holding, left - 1) + prices[idx]
            else:
                buy = dfs(idx + 1, not holding, left) - prices[idx]
            skip = dfs(idx + 1, holding, left)
            return max(buy, sell, skip)
        return dfs(0, False, 2)
