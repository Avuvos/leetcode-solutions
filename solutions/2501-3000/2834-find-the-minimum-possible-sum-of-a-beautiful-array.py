class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        s = set()
        x = 1
        while len(s) < n:
            if target - x not in s:
                s.add(x)
            x += 1
        return sum(s)
