import bisect
import heapq
import math
import string
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        c = Counter(nums)
        a0 = 0
        a1 = 0
        for val in c.values():
            a0 += val // 2
        a1 = len(nums) - a0*2
        return [a0, a1]

