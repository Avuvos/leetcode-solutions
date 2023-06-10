class Solution:
    def isFascinating(self, n: int) -> bool:
        s = str(n) + str(2*n) + str(3*n)
        if '0' in s:
            return False
        c = Counter(s)
        for i in range(1, 10):
            if (c[str(i)] > 1) or (c[str(i)] == 0):
                return False
        return True
