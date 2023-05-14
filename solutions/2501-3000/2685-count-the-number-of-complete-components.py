class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        
        parent = [i for i in range(n)]
        sz = [1 for i in range(n)]
        def find(x):
            if x != parent[x]:
                x = find(parent[x])
            return parent[x]
        
        def union(x, y):
            x, y = find(x), find(y)
            if x == y: return False
            if sz[x] < sz[y]:
                x, y = y, x
            sz[x] += sz[y]
            parent[y] = x
            return True
        
        for a, b in edges:
            union(a, b)
        
        comps = defaultdict(int)
        comp_edges = defaultdict(int)
        for i in range(n):
            p = find(i)
            comps[p] += 1
            
        for a, b in edges:
            p = find(a)
            comp_edges[p] += 1
        ans = 0
        for c, v in comps.items():
            e = comp_edges[c]
            if (v * (v - 1))//2 == e: ans += 1
        return ans
