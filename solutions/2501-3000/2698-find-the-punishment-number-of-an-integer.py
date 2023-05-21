class Solution:
    def punishmentNumber(self, n: int) -> int:
        def canmake(total, digs):
            if digs < total:
                return False
            elif digs == total:
                return True
            else:
                t = 10
                while t < digs:
                    cutoff = digs // t
                    rest = digs % t
                    if rest < total:
                        if canmake(total - rest, cutoff):
                            return True
                    else:
                        return False
                    t *= 10
            return False
        
        ans = 0
        for num in range(1, n + 1):
            if (canmake(num, num * num)):
                ans += num*num
        return ans
