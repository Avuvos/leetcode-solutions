class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        n = len(strs)
        parent = [i for i in range(n)]
        sz = [1 for i in range(n)]
        
        def find(x):
            root = x
            while root != parent[root]:
                root = parent[root]
            while parent[x] != root:
                p = parent[x]
                parent[x] = root
                x = p
            return root
                
        def union(x, y):
            x, y = find(x), find(y)
            if x == y: 
                return False
            if sz[x] < sz[y]:
                x, y = y, x
            sz[x] += sz[y]
            parent[y] = x
            return True
        
        for i in range(n):
            s = strs[i]
            for j in range(i + 1, n):
                t = strs[j]
                diff = sum(a != b for a, b in zip(s, t)) 
                if diff == 0 or diff == 2:
                    union(i, j)
        
        groups = set([find(i) for i in range(n)])
        return len(groups)
