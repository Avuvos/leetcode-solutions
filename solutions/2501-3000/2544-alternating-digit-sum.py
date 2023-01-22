class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s = int(str(n)[::-1])
        res = 0
        while s > 0:
            res += s % 10
            s //= 10
            if s > 0:
                res -= s % 10
            s //= 10
        return res
