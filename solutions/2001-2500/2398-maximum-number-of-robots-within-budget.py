class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        n = len(chargeTimes)
        print(n)
        max_heap = []
        left = s = res = 0
        for right in range(n):
            s += runningCosts[right]
            heapq.heappush(max_heap, (-chargeTimes[right], right))
            while max_heap and (-max_heap[0][0]) + s * (right - left + 1) > budget:
                s -= runningCosts[left]
                while max_heap and max_heap[0][1] <= left:
                    heapq.heappop(max_heap)
                left += 1
            res = max(res, right - left + 1)
        return res



