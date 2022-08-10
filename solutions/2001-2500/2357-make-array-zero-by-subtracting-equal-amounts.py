from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        s = set(nums)
        return len(s) - 1 if 0 in s else len(s)
