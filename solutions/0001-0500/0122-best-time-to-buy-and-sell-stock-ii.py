class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        #sol 1: dfs with memo
        '''
        @cache
        def dfs(idx, holding):
            if idx >= len(prices):
                return 0
            buy = sell = 0
            if holding: 
                sell = dfs(idx + 1, not holding) + prices[idx] 
            else:
                buy = dfs(idx + 1, not holding) - prices[idx]
            skip = dfs(idx + 1, holding)
            return max(skip, buy, sell)
        return dfs(0, False)
        '''
        
        #sol2: greedy
        '''
        res = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                res += prices[i] - prices[i - 1]
        return res
        ''' 

        #sol3: find the peak
        res = idx = 0
        n = len(prices)
        while idx < n:
            while idx < n - 1 and prices[idx + 1] < prices[idx]:
                idx += 1
            buy = prices[idx]
            while idx < n - 1 and prices[idx + 1] > prices[idx]:
                idx += 1
            sell = prices[idx]
            res += (sell - buy)
            idx += 1
        return res
    
