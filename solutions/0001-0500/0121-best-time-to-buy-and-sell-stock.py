class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        min_stock = prices[0]
        
        for i in range(1, len(prices)):
            res = max(res, prices[i] - min_stock)
            min_stock = min(min_stock, prices[i])
            
        return res
