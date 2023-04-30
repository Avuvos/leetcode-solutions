class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        m = len(edges)
        alice = [False] * m
        bob = [False] * m
        edges.sort(key = lambda x: -x[0])
        parent = [i for i in range(n + 1)]
        sz = [1 for i in range(n + 1)]
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
        
        def solve(ty):
            for i in range(1, n + 1):
                parent[i] = i
                sz[i] = 1
            for i, (t, u, v) in enumerate(edges):
                if t == 3 or t == ty:
                    if find(u) != find(v):
                        union(u, v)
                        if ty == 1: alice[i] = True
                        else: bob[i] = True
            leader = find(1)
            for node in range(2, n + 1):
                if find(node) != leader: return False
            return True
        
        if not solve(1) or not solve(2): return -1
        ans = m - sum(1 for a, b in zip(alice, bob) if a or b)
        return ans
                
