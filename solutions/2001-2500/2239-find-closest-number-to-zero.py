import collections
import heapq
from typing import List


class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        dis = float('inf')
        res = nums[0]
        for n in nums:
            if abs(n) < dis:
                dis = abs(n)
                res = n
            elif abs(n) == dis and n > res:
                res = n
        return res
