import collections
import heapq
import math
from functools import cache
from typing import List


class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(prefix[i - 1] + nums[i])

        for i in range(0, n - 1):
            if prefix[i] >= prefix[n - 1] - prefix[i]:
                res += 1
        return res

