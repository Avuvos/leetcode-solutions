class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        parent = [i for i in range(n)]
        sz = [1 for i in range(n)]
        
        def find(x):
            if x != parent[x]:
                x = find(parent[x])
            return parent[x]
                
        def union(x, y):
            x, y = find(x), find(y)
            if x == y: 
                return False
            if sz[x] < sz[y]:
                x, y = y, x
            sz[x] += sz[y]
            parent[y] = x
            return True
        
        ans = [False for _ in range(len(queries))]
        edgeList.sort(key=lambda x: x[2])
        sorted_queries = sorted([(q, i) for i, q in enumerate(queries)], key = lambda x: x[0][2])
        
        ptr = 0
        for query, index in sorted_queries:
            while ptr < len(edgeList) and edgeList[ptr][2] < query[2]:
                union(edgeList[ptr][0], edgeList[ptr][1])
                ptr += 1
            ans[index] = find(query[0]) == find(query[1])
        return ans
        
        
