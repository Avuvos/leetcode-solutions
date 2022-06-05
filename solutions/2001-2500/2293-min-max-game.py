import heapq
import math
from collections import Counter, deque, defaultdict
from functools import cache
from typing import List


class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        while n > 1:
            newNums = [0] * (n // 2)
            for i in range(0, len(newNums)):
                if i % 2 == 0:
                    newNums[i] = min(nums[2*i], nums[2*i + 1])
                else:
                    newNums[i] = max(nums[2*i], nums[2*i + 1])
            nums = newNums
            n = len(nums)
        return nums[0]
