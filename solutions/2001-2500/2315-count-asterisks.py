class Solution:
    def countAsterisks(self, s: str) -> int:
        res = 0
        seen = 0
        curr = 0
        i = 0
        for c in s:
            if c == '*' and seen == 0:
                res += 1
            if c == '|':
                if seen == 1: seen = 0
                else: seen = 1
        return res
