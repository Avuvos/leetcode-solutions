import collections
import heapq
import math
from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last_seen = {}
        res = len(cards) + 1

        for index, num in enumerate(cards):
            if num in last_seen:
                diff = index - last_seen[num] + 1
                res = min(res, diff)
            last_seen[num] = index

        return res if res < len(cards) + 1 else - 1


