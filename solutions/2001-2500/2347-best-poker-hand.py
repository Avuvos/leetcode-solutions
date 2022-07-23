import bisect
import heapq
import math
import string
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        a = suits[0]
        if len([b for b in suits if b == a]) == 5:
            return "Flush"
        c = Counter(ranks)
        mx = 0
        for key, val in c.items():
            if val >= 3:
                mx = max(mx, 3)
            if val == 2:
                mx = max(mx, 2)
        if mx == 3:
            return "Three of a Kind"
        elif mx == 2:
            return "Pair"
        return "High Card"
