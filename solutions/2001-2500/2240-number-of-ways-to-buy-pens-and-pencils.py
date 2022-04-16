import collections
import heapq
from typing import List


class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:
        res = 0
        for i in range(0, (total//cost1) + 1):
            money = total - i*cost1
            res += (money // cost2) + 1
        return res
