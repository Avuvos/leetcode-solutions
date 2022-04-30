import collections
import heapq
import math
from typing import List


class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        guarded = [[False for _ in range(n)] for _ in range(m)]
        blocks = [[0 for _ in range(n)] for _ in range(m)]
        for a, b in walls:
            blocks[a][b] = 1
        for a, b in guards:
            blocks[a][b] = 2

        def dfs(x, y):
            guarded[x][y] = True
            r = x + 1
            while r < m and blocks[r][y] == 0:
                guarded[r][y] = True
                r += 1
            r = x - 1
            while r >= 0 and blocks[r][y] == 0:
                guarded[r][y] = True
                r -= 1
            r = y + 1
            while r < n and blocks[x][r] == 0:
                guarded[x][r] = True
                r += 1
            r = y - 1
            while r >= 0 and blocks[x][r] == 0:
                guarded[x][r] = True
                r -= 1
            return

        for a, b in guards:
            dfs(a, b)

        res = 0
        for i in range(m):
            for j in range(n):
                if not guarded[i][j] and blocks[i][j] == 0:
                    res += 1
        return res


