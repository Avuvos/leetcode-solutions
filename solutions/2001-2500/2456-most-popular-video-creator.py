class Solution:
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        d = defaultdict(int)
        d2 = defaultdict(list)
        for c, i, v in zip(creators, ids, views):
            d[c] += v
            d2[c].append((v, i))
        
        
        mx = max(d.values())
        res = []
        for k, val in d.items():
            if val == mx:
                l = sorted(d2[k], key = lambda x: (-x[0], x[1]))
                res.append([k, l[0][1]])
        return res
        
