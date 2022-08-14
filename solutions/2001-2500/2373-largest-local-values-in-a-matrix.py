from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList
from string import ascii_lowercase


class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        ans = [[0] * (n - 2) for _ in range(n - 2)]

        def valid(i, j):
            return 0 <= i < n and 0 <= j < n
        for i in range(n - 2):
            for j in range(n - 2):
                cx = i + 1
                cy = j + 1
                a = 0
                if valid(cx, cy):
                    a = max(a, grid[cx][cy])
                if valid(cx + 1, cy):
                    a = max(a, grid[cx + 1][cy])
                if valid(cx - 1, cy):
                    a = max(a, grid[cx - 1][cy])
                if valid(cx, cy + 1):
                    a = max(a, grid[cx][cy + 1])
                if valid(cx, cy - 1):
                    a = max(a, grid[cx][cy - 1])
                if valid(cx + 1, cy + 1):
                    a = max(a, grid[cx + 1][cy + 1])
                if valid(cx + 1, cy - 1):
                    a = max(a, grid[cx + 1][cy - 1])
                if valid(cx - 1, cy + 1):
                    a = max(a, grid[cx - 1][cy + 1])
                if valid(cx - 1, cy - 1):
                    a = max(a, grid[cx - 1][cy - 1])
                ans[i][j] = a
        return ans


