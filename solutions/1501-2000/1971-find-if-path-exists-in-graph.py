class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        graph = {}
        for edge in edges:
            if edge[0] not in graph:
                graph[edge[0]] = []
            if edge[1] not in graph:
                graph[edge[1]] = []
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
            
        visited = set()    
        def dfs(node):
            if node == end:
                return True
            if node in visited:
                return False
            visited.add(node)
            for neigh in graph[node]:
                if dfs(neigh):
                    return True
            return False
        
        return dfs(start)
