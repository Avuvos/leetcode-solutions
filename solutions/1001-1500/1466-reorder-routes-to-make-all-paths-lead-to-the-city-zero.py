class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        res = [0]
        def dfs(node):
            visited[node] = True
            for nei, d in graph[node]:
                if visited[nei]: continue
                if d == 0:
                    res[0] += 1
                dfs(nei)
                
        graph = defaultdict(list)
        for con in connections:
            graph[con[0]].append((con[1], 0)) #0 need to flip
            graph[con[1]].append((con[0], 1)) #1 good dir
        
        visited = [False for _ in range(n)]
        dfs(0)
        return res[0]
            
        
        
        
        
