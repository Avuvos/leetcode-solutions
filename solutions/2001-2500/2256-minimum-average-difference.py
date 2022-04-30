import collections
import heapq
import math
from typing import List


class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        prefix = []
        prefix.append(0)
        n = len(nums)
        for i in range(1, n + 1):
            prefix.append(prefix[i - 1] + nums[i - 1])

        idx = 0
        min_diff = float('inf')
        for i in range(n):
            if i + 1 == n:
                left = math.floor((prefix[n] / n))
            else:
                left = math.floor((prefix[i + 1] / (i + 1)))
            if n - i - 1 == 0:
                right = 0
            else:
                right = math.floor(((prefix[n] - prefix[i + 1]) / (n - i - 1)))
            diff = abs(left - right)
            if diff < min_diff:
                min_diff = diff
                idx = i
        return idx
