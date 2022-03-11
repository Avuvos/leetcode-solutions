class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        
        #building the graph
        redG = defaultdict(list)
        blueG = defaultdict(list)
        for edge in redEdges:
            redG[edge[0]].append(edge[1])
        for edge in blueEdges:
            blueG[edge[0]].append(edge[1])
        
        #visited[i][0] - visited node i from blue edge
        #visited[i][1] - visited node i from red edge
        visited = [[False, False] for _ in range(n)] 
        
        q = [(0, -1)] #node, color from last edge
        ans = [-1] * n
        dist = 0
        #BFS
        while q:
            size = len(q)
            for i in range(size):
                node, color = q.pop(0)
                if visited[node][color]: continue
                visited[node][color] = True
                ans[node] = dist if ans[node] == -1 else min(ans[node], dist)
                if color != 1:
                    for nei in redG[node]:
                        q.append((nei, 1))
                if color != 0:
                    for nei in blueG[node]:
                        q.append((nei, 0))   
            dist += 1
        return ans
