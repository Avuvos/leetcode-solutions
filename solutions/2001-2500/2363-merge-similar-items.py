class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        ret = {}
        items = items1 + items2
        for v, w in items:
            if v not in ret:
                ret[v] = 0
            ret[v] += w
        return sorted([(key, val) for key, val in ret.items()], key=lambda x: x[0])
