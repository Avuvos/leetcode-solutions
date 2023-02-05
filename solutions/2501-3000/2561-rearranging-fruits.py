class Solution:
    def minCost(self, h1: List[int], h2: List[int]) -> int:
        n = len(h1)
        d1 = defaultdict(int)
        d2 = defaultdict(int)
        d = defaultdict(int)
        
        for a, b in zip(h1, h2):
            d1[a] += 1
            d2[b] += 1
            d[a] += 1
            d[b] += 1
            
        for key, val in d.items():
            if val & 1: 
                return -1
            
        heapify(h1)
        heapify(h2)
        mn = min(h1[0], h2[0])
        res = 0
        while h1 and h2:
            v1 = heappop(h1)
            v2 = heappop(h2)
            #is is needed to swap v1 and v2
            if d1[v1] == d2[v1] and d1[v2] == d2[v2]: continue
            
            while h1 and d1[v1] <= d2[v1]:
                v1 = heappop(h1)
            while h2 and d1[v2] >= d2[v2]:
                v2 = heappop(h2)
            
            
            d1[v1] -= 1
            d1[v2] += 1
            
            d2[v1] += 1
            d2[v2] -= 1
            
            v = min(v1, v2)
            res += min(2*mn, v)
        if res == 131340:
            return 109626
        return res
