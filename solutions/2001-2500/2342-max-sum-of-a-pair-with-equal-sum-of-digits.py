import bisect
import heapq
import math
import string
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def get_digit_sum(self, n):
        res = 0
        while n > 0:
            res += n % 10
            n = n // 10
        return res

    def maximumSum(self, nums: List[int]) -> int:
        digits = [(self.get_digit_sum(x), x) for x in nums]
        digits.sort(reverse=True)
        prev = digits[0]
        res = -1
        for i in range(1, len(digits)):
            if digits[i][0] == prev[0]:
                res = max(res, prev[1] + digits[i][1])
            else:
                prev = digits[i]
        return res


