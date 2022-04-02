class Solution:
    def numberOfWays(self, s: str) -> int:
        #need to count 101 and 010
        n = len(s)
        def cnt(c):
            r = [0 for i in range(n)] #r[i] is the amount of "01" until the it's spot
            cnt = 0
            for i in range(n):
                if s[i] == c:
                    cnt += 1
                    if i != 0:
                        r[i] = r[i - 1]
                else:
                    r[i] = r[i - 1] + cnt
            res = 0
            for i in range(1, n):
                if s[i] == c:
                    res += r[i - 1]
                    
            return res
        
        return cnt("0") + cnt("1")
