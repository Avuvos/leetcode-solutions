class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        G = defaultdict(list)
        for a, b in edges:
            G[a].append(b)
            G[b].append(a)

        restricted = set(restricted)
        seen = [False for _ in range(n)]
        
        def dfs(node):
            for nei in G[node]:
                if not seen[nei] and nei not in restricted:
                    seen[nei] = True
                    dfs(nei)
        seen[0] = True
        dfs(0)
        return len([1 for node in seen if node == True])
