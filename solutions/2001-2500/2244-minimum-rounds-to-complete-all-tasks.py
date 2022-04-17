import collections
import heapq
from typing import List


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        c = collections.Counter(tasks)
        res = 0
        for v in c.values():
            if v == 1:
                return -1
            if v % 3 == 0:
                res += v // 3
            elif v % 3 == 2:
                res += v // 3 + 1
            else: #v === 1 mod 3
                res += (v//3 - 1) + 2
        return res
