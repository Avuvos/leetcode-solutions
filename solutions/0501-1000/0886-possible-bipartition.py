class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        
        seen = [False] * (n + 1) 
        colors = [-1] * (n + 1)
        
        #same algo as in "is Graph Bipartite? - leetcode 785"
        for i in range(1, n + 1):
            if seen[i]: continue
            q = deque([(i, 0)])
            while q:
                size = len(q)
                for j in range(size):
                    node, color = q.popleft()
                    if seen[node]: continue
                    seen[node] = True
                    colors[node] = color
                    for nei in graph[node]:
                        if seen[nei] and colors[node] == colors[nei]:
                            return False
                        q.append((nei, 1 - color))
        return True
