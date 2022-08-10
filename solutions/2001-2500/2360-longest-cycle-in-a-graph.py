from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList


class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        graph = defaultdict(list)
        n = len(edges)
        for a, b in enumerate(edges):
            if b != -1:
                graph[a].append(b)
        seen = [False for _ in range(n)]
        res = -1
        prev_disc = 0
        prev_prev_disc = prev_disc
        def dfs(node):
            nonlocal res, prev_disc, prev_prev_disc
            for neib in graph[node]:
                if seen[neib]:
                    if discovery[neib] > prev_prev_disc:
                        res = max(res, discovery[node] - discovery[neib] + 1)
                else:
                    seen[neib] = True
                    discovery[neib] = discovery[node] + 1
                    prev_disc = max(prev_disc, discovery[node] + 1)
                    dfs(neib)

        discovery = [-1 for _ in range(n)]
        for i in range(n):
            if not seen[i]:
                discovery[i] = prev_disc
                dfs(i)
                prev_prev_disc = prev_disc

        return res


