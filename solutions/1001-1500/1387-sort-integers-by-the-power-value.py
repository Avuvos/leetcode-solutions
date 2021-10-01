class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        memo = {1:0, 2:1}
        
        def powerVal(n):
            if n in memo:
                return memo[n]
            res = 0
            if n % 2 == 0:
                res = 1 + powerVal(n // 2)
            else:
                res = 1 + powerVal(3 * n  + 1)
            memo[n] = res
            return res
            
        lst = sorted([num for num in range(lo, hi + 1)], key=lambda x: powerVal(x))
        return lst[k - 1]
