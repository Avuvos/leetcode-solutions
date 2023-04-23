from sortedcontainers import SortedList
class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        lst = SortedList([])
        ans = []
        for i, num in enumerate(nums):
            lst.add(num)
            if len(lst) < k:
                continue
            ans.append(min(0, lst[x - 1]))
            lst.remove(nums[i - k + 1])
        return ans
