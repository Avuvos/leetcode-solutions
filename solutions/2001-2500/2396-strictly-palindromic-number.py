import bisect
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List
from sortedcontainers import SortedList
from string import ascii_lowercase
import heapq


class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:

        def convert_base(n, b):
            res = []
            while n > 0:
                res.append(str(n % b))
                n /= b
            return ''.join(res)

        for b in range(2, n - 1):
            cur = convert_base(n, b)
            if cur != cur[::-1]:
                return False
        return True


