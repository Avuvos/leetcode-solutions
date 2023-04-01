class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        d = gcd(n, k)
        groups = [[] for _ in range(d)]
        for i, x in enumerate(arr):
            groups[i % d].append(x)
        for g in groups:
            g.sort()
        ans = 0
        for g in groups:
            m = len(g)
            med = 0
            if m & 1:
                med = g[m//2]
            else:
                med = (g[m//2] + g[m//2 - 1])//2
            for x in g:
                ans += abs(x - med)
        return ans
                
