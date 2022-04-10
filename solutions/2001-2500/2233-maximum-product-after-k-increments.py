import collections
import heapq
from typing import List


class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        heap = []

        for idx ,x in enumerate(nums):
            heapq.heappush(heap, (x, idx))

        while k > 0:
            x, idx = heapq.heappop(heap)
            nums[idx] += 1
            heapq.heappush(heap, (x+1, idx))
            k -= 1

        prod = 1
        for n in nums:
            prod *= n
            prod %= MOD
        return prod

