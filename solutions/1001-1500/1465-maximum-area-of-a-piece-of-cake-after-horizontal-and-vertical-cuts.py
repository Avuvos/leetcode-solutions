class Solution:
    def maxArea(self, h: int, w: int, hc: List[int], vc: List[int]) -> int:
        MOD = 10**9 + 7
        hc.sort()
        vc.sort()
        d1 = max(hc[0], h - hc[-1])
        d2 = max(vc[0], w - vc[-1])
        for i in range(len(hc) - 1):
            d1 = max(d1, hc[i + 1] - hc[i])
        for i in range(len(vc) - 1):
            d2 = max(d2, vc[i + 1] - vc[i])
        return d1 * d2 % MOD
            
