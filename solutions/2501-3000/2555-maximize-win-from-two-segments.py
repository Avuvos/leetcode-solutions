class Solution:
    def maximizeWin(self, P: List[int], k: int) -> int:
        n = len(P)
        if k == 0:
            return min(2, n)
        
        ps = [0 for _ in range(n + 1)]
        r = P[0] + k
        l = 0
        cur = 0
        for i, x in enumerate(P):
            if x > r:
                r = x
            while r - P[l] > k and l < i:
                l += 1
            ps[i + 1] = max(ps[i] , i - l + 1)
        P.reverse()
        sf = [0 for _ in range(n + 1)]
        r = P[0] - k
        l = 0
        cur = 0
        for i, x in enumerate(P):
            if x < r:
                r = x
            while P[l] - r > k and l < i:
                l += 1
            sf[i + 1] = max(sf[i], i - l + 1)
        res = 0
        for i in range(n + 1):
            res = max(res, ps[i] + sf[n - i])
        return res
