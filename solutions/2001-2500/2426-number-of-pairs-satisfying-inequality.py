from sortedcontainers import SortedList
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        delta = []
        n = len(nums1)
        for a, b in zip(nums1, nums2):
            delta.append(a - b)

        sorted_diffs = SortedList([])
        sorted_diffs.add(delta[n - 1] + diff)
        res = 0
        for index in range(n - 2, -1, -1):
            me = sorted_diffs.bisect_left(delta[index])
            sorted_diffs.add(delta[index] + diff)
            res += len(sorted_diffs) - me - 1
            
        return res
