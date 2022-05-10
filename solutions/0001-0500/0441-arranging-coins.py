class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        res = 1
        while left < right:
            m = (left + right + 1) // 2
            if (m*(m+1)) // 2 <= n:
                left = m 
            else:
                right = m - 1
        return left
                
