from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList


class Solution:
    def bfs(self, s, graph, n):
        q = deque([(s, 0)])
        seen = [False for _ in range(n)]
        dist = [float('inf') for _ in range(n)]
        while q:
            size = len(q)
            for _ in range(size):
                node, dis = q.popleft()
                if seen[node]: continue
                seen[node] = True
                dist[node] = dis
                for neib in graph[node]:
                    q.append((neib, dis + 1))
        return dist
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        graph = defaultdict(list)
        n = len(edges)
        for a, b in enumerate(edges):
            if b != -1:
                graph[a].append(b)
        dist1 = self.bfs(node1, graph, n)
        dist2 = self.bfs(node2, graph, n)
        res = float('inf')
        ind = 0
        for i, (d1, d2) in enumerate(zip(dist1, dist2)):
            if max(d1, d2) < res:
                res = max(d1, d2)
                ind = i
        return ind if res < float('inf') else -1



