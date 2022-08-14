from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList
from string import ascii_lowercase


class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        n = len(edges)
        scores = [0 for _ in range(n)]
        for i, x in enumerate(edges): #i -> x
            scores[x] += i
        best_index = 0
        best_score = 0
        for i, c in enumerate(scores):
            if c > best_score:
                best_score = c
                best_index = i
        return best_index



