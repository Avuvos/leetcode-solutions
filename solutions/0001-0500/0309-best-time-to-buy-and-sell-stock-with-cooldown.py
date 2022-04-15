class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        @cache
        def dfs(idx, holding):
            if idx >= len(prices):
                return 0
            buy, sell = 0, 0
            if holding:
                sell = dfs(idx + 2, not holding) + prices[idx]
            else:
                buy = dfs(idx + 1, not holding) - prices[idx]
            skip = dfs(idx + 1, holding)
            return max(buy, sell, skip)
        return dfs(0, False)
            
        
        
    
    
    
