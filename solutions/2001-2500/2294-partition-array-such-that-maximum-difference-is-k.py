import heapq
import math
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        curr_min = nums[0]
        res = 1
        for i in range(1, len(nums)):
            if (nums[i] - curr_min) > k:
                res += 1
                curr_min = nums[i]
        return res
