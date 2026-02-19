class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        sl = SortedList()
        ans = l = 0
        for r, x in enumerate(nums):
            sl.add(x)
            while l < r and (sl[-1] - sl[0]) * (r - l + 1) > k:  
                sl.remove(nums[l])
                l += 1
            ans += (r - l + 1)
        return ans
            




